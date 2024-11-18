volatile int etx_value;
#include <asm/io.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/kdev_t.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/slab.h> //kmalloc()
#include <linux/sysfs.h>
#include <linux/uaccess.h>   //copy_to/from_user()
#include <linux/workqueue.h> // Required for workqueues
#define DRIVER_AUTHOR "Beloin <beloin.rodrigues@gmail.com>"
#define DRIVER_DESC "A simple Workqueue driver"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

// Already existing defines
// #define create_workqueue(name) alloc_workqueue("%s", WQ_MEM_RECLAIM, 1,
// (name)) #define create_singlethread_workqueue(name) alloc_workqueue("%s",
// WQ_UNBOUND | WQ_MEM_RECLAIM, 1, (name))

#define IRQ_NO 11

static struct workqueue_struct *own_workqueue;

static void workqueue_fn(struct work_struct *work);

static DECLARE_WORK(work, workqueue_fn);

static irqreturn_t irq_handler(int irq, void *dev_id);

int init_module(void) {
  own_workqueue = create_workqueue("beloinswq");
  printk(KERN_INFO "Initializing Workqueue register");
  return 0;
}

void cleanup_module(void) { printk(KERN_INFO "Ending Workqueue register"); }

static irqreturn_t irq_handler(int irq, void *dev_id) {
  printk(KERN_INFO "Shared IRQ: Interrupt Occurred\n");
  /*Allocating work to queue*/
  queue_work(own_workqueue, &work);

  return IRQ_HANDLED;
}

static void workqueue_fn(struct work_struct *work) {
  printk(KERN_INFO "Executing %s Workqueue Function\n", "beloinswq");
  // FILE *f = fopen("/home/beloin/mywq.log", "a");
  // fprintf(f, "Logged in %s\n");
  return;
}

/*
 * Why Volatile?
 */
volatile int etx_value = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
struct kobject *kobj_ref;

/*
* Function Prototypes
*/
static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
