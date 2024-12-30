////////////////////////////////////////////////////////////////////////////////
// File:        workqueue_setup.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef WORKQUEUE_SETUP_H
#define WORKQUEUE_SETUP_H

#include <linux/workqueue.h>

void execute_workqueue(struct work_struct *work);

static struct workqueue_struct *own_workqueue;

static DECLARE_WORK(work, execute_workqueue);

#endif /* WORKQUEUE_SETUP_H */
