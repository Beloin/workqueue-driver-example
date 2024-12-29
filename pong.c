#include <linux/module.h>
#include "device_setup.h"
#include "linux/cdev.h"
#include "workqueue_setup.h"

#define DRIVER_AUTHOR "Beloin <beloin.rodrigues@gmail.com>"
#define DRIVER_DESC "A simple Workqueue driver"
#define DRIVER_LICENSE "GPL"
#define DRIVER_VERSION "0.0.1"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE(DRIVER_LICENSE);


static struct workqueue_struct *own_workqueue;

static DECLARE_WORK(work, execute_workqueue);

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

/*
** This fuction will be called when we read the sysfs file
*/
static ssize_t sysfs_show(struct kobject *kobj, struct kobj_attribute *attr,
                          char *buf) {
  // TODO: Undestand better this kobject and attr
  printk(KERN_INFO "Sysfs - Read!!!\n");
  return sprintf(buf, "%d", etx_value);
}

/*
** This fuction will be called when we write the sysfsfs file
*/
static ssize_t sysfs_store(struct kobject *kobj, struct kobj_attribute *attr,
                           const char *buf, size_t count) {
  printk(KERN_INFO "Sysfs - Write!!!\n");
  sscanf(buf, "%d", &etx_value);
  return count;
}

static int __init etx_driver_init(void) {
  /*Allocating Major number*/
  if ((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) < 0) {
    printk(KERN_INFO "Cannot allocate major number\n");
    return -1;
  }
  printk(KERN_INFO "Major = %d Minor = %d \n", MAJOR(dev), MINOR(dev));

  /*Creating cdev structure*/
  cdev_init(&etx_cdev, &fops);

  /*Adding character device to the system*/
  if ((cdev_add(&etx_cdev, dev, 1)) < 0) {
    printk(KERN_INFO "Cannot add the device to the system\n");
    goto r_class;
  }

  /*Creating struct class*/
  if (IS_ERR(dev_class = class_create(THIS_MODULE, "etx_class"))) {
    printk(KERN_INFO "Cannot create the struct class\n");
    goto r_class;
  }

  /*Creating device*/
  if (IS_ERR(device_create(dev_class, NULL, dev, NULL, "etx_device"))) {
    printk(KERN_INFO "Cannot create the Device 1\n");
    goto r_device;
  }

  /*Creating a directory in /sys/kernel/ */
  kobj_ref = kobject_create_and_add("etx_sysfs", kernel_kobj);

  /*Creating sysfs file for etx_value*/
  if (sysfs_create_file(kobj_ref, &etx_attr.attr)) {
    printk(KERN_INFO "Cannot create sysfs file......\n");
    goto r_sysfs;
  }

  /*Creating workqueue */
  own_workqueue = create_workqueue("own_wq");

  printk(KERN_INFO "Device Driver Insert...Done!!!\n");
  return 0;

r_sysfs:
  kobject_put(kobj_ref);
  sysfs_remove_file(kernel_kobj, &etx_attr.attr);

r_device:
  class_destroy(dev_class);
r_class:
  unregister_chrdev_region(dev, 1);
  cdev_del(&etx_cdev);
  return -1;
}

/*
** Module exit function
*/
static void __exit etx_driver_exit(void) {
  /* Delete workqueue */
  destroy_workqueue(own_workqueue);
  kobject_put(kobj_ref);
  sysfs_remove_file(kernel_kobj, &etx_attr.attr);
  device_destroy(dev_class, dev);
  class_destroy(dev_class);
  cdev_del(&etx_cdev);
  unregister_chrdev_region(dev, 1);
  printk(KERN_INFO "Device Driver Remove...Done!!!\n");
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);
