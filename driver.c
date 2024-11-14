
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Beloin <beloin.rodrigues@gmail.com>"
#define DRIVER_DESC   "A simple Workqueue driver"

MODULE_LICENSE("GPL");

int init_module(void) {
  printk(KERN_INFO "Initializing Workqueue register");
  return 0;
}


void cleanup_module(void)
{
  printk(KERN_INFO "Ending Workqueue register");
}

// void register_wq(){
//   alloc_workqueue("%s", WQ_MEM_RECLAIM, 1, (name))
// }
