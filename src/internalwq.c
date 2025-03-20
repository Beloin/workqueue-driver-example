// #include "internalwq.h"

#include "linux/printk.h"

void execute(void) {
  printk(KERN_INFO "Executing Internal SRC %s Workqueue Function\n", "beloinswq");
}


