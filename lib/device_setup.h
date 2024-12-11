////////////////////////////////////////////////////////////////////////////////
// File:        device_setup.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICE_SETUP_H
#define DEVICE_SETUP_H


#include "linux/types.h"
#include <linux/fs.h>

#define DEVICE_NAME "pong_dev"

static int dev_open(struct inode *inode, struct file *file);
static int dev_release(struct inode *inode, struct file *file);
static ssize_t dev_read(struct file *filp, char __user *buf, size_t len,
                        loff_t *off);
static ssize_t dev_write(struct file *filp, const char *buf, size_t len,
                         loff_t *off);

#endif /* DEVICE_SETUP_H */
