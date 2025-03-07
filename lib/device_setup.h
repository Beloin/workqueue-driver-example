////////////////////////////////////////////////////////////////////////////////
// File:        device_setup.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICE_SETUP_H
#define DEVICE_SETUP_H

#include "linux/types.h"
#include <linux/fs.h>

#define DEVICE_NAME "pong_dev"

int my_dev_open(struct inode *inode, struct file *file);
// int my_dev_open(struct inode *inode, struct file *file) {
//   printk(KERN_INFO "my_device File Opened...!!!\n");
//   return 0;
// }
EXPORT_SYMBOL(my_dev_open);

int my_dev_release(struct inode *inode, struct file *file);
// EXPORT_SYMBOL(my_dev_release);

ssize_t my_dev_read(struct file *filp, char __user *buf, size_t len,
                    loff_t *off);
// EXPORT_SYMBOL(my_dev_read);

ssize_t my_dev_write(struct file *filp, const char *buf, size_t len,
                     loff_t *off);
// EXPORT_SYMBOL(my_dev_write);

ssize_t my_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
// EXPORT_SYMBOL(my_dev_ioctl);

#endif /* DEVICE_SETUP_H */
