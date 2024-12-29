#include <linux/module.h>
#include "device_setup.h"

#define DRIVER_AUTHOR "Beloin <beloin.rodrigues@gmail.com>"
#define DRIVER_DESC "A simple Workqueue driver"
#define DRIVER_LICENSE "GPL"
#define DRIVER_VERSION "0.0.1"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE(DRIVER_LICENSE);

/*
 * Device Setup
 */

volatile int etx_value = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
struct kobject *kobj_ref;

// Driver init
static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);

// sysfs Functions
static ssize_t sysfs_show(struct kobject *kobj, struct kobj_attribute *attr,
                          char *buf);
static ssize_t sysfs_store(struct kobject *kobj, struct kobj_attribute *attr,
                           const char *buf, size_t count);

struct kobj_attribute etx_attr =
    __ATTR(etx_value, 0660, sysfs_show, sysfs_store);

/*
 * File Operations
 */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = dev_read,
    .write = dev_write,
    .open = dev_open,
    .release = dev_release,
};
