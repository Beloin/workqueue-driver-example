////////////////////////////////////////////////////////////////////////////////
// File:        workqueue_setup.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef WORKQUEUE_SETUP_H
#define WORKQUEUE_SETUP_H

#include <linux/workqueue.h>
#include "internalwq.h"

void workqueue_handler(struct work_struct *work);

// Multiple defitions :(
extern struct workqueue_struct *own_workqueue;

static DECLARE_WORK(my_work, workqueue_handler);

#endif /* WORKQUEUE_SETUP_H */
