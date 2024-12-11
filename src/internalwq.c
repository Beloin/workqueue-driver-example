#include "internalwq.h"

#include "linux/printk.h"

void execute(void) {
  printk(KERN_INFO "Executing %s Workqueue Function\n", "beloinswq");
}
