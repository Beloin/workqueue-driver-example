#include "linux/printk.h"
#include <linux/fs.h>

#include "device_setup.h"

int dev_open(struct inode *inode, struct file *file) {
  printk(KERN_INFO "Device File Opened...!!!\n");
  return 0;
}

int dev_release(struct inode *inode, struct file *file) {
  printk(KERN_INFO "Device File Closed...!!!\n");
  return 0;
}
ssize_t dev_read(struct file *filp, char __user *buf, size_t len, loff_t *off) {
  printk(KERN_INFO "Read function\n");
  printk(KERN_INFO "Allocating workqueue\n");
  /*Allocating work to queue*/
  // queue_work(own_workqueue, &work);
  return 0;
}

ssize_t dev_write(struct file *filp, const char *buf, size_t len, loff_t *off) {
  printk(KERN_INFO "Write Function, Called by %s\n", buf);
  return 0;
}
