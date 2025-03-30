#include "internalwq.h"
#include "asm-generic/fcntl.h"
#include "file_utils.h"
#include "linux/printk.h"

void execute(void) {
  printk(KERN_INFO "Executing %s Workqueue Function\n",
         "beloinswq");
  struct file *fp = file_open("/home/beloin/Documents/software/linux/workqueue_driver/new_random_file.txt", O_WRONLY | O_APPEND, 0666);
  char *buffer = "Hello Pong!";
  file_write(fp, 0, buffer, strlen(buffer));
  file_close(fp);
  printk(KERN_INFO "Done executing %s Workqueue\n", "beloinswq");
}
