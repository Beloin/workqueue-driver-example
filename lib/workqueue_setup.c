#include "workqueue_setup.h"
// #include "internalwq.h"

void execute_workqueue(struct work_struct *work) {
  printk(KERN_INFO "Executing %s Workqueue Function\n", "beloinswq");
  // execute();
  // FILE *f = fopen("/home/beloin/mywq.log", "a");
  // fprintf(f, "Logged in %s\n");
  return;
}
