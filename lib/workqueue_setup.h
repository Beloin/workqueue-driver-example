////////////////////////////////////////////////////////////////////////////////
// File:        workqueue_setup.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef WORKQUEUE_SETUP_H
#define WORKQUEUE_SETUP_H

#include <linux/workqueue.h>

void workqueue_handler(struct work_struct *work) {
  printk(KERN_INFO "Executing %s Workqueue Function\n", "beloinswq");
}

struct workqueue_struct *own_workqueue;

static DECLARE_WORK(my_work, workqueue_handler);

#endif /* WORKQUEUE_SETUP_H */
