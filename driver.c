#include "linux/workqueue.h"
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#define DRIVER_AUTHOR "Beloin <beloin.rodrigues@gmail.com>"
#define DRIVER_DESC "A simple Workqueue driver"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

// Already existing defines
// #define create_workqueue(name) alloc_workqueue("%s", WQ_MEM_RECLAIM, 1,
// (name)) #define create_singlethread_workqueue(name) alloc_workqueue("%s",
// WQ_UNBOUND | WQ_MEM_RECLAIM, 1, (name))

static void workqueue_fn(struct work_struct *work);

static DECLARE_WORK(work, workqueue_fn);

int init_module(void) {
  struct workqueue_struct *myqw = create_workqueue("beloinswq");
  printk(KERN_INFO "Initializing Workqueue register");
  return 0;
}

void cleanup_module(void) { printk(KERN_INFO "Ending Workqueue register"); }

static void workqueue_fn(struct work_struct *work) {}
