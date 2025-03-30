#include <file_utils.h>
#include <linux/buffer_head.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

struct file *file_open(const char *path, int flags, int rights) {
  struct file *filp = NULL;

  filp = filp_open(path, flags, rights);
  if (IS_ERR(filp)) {
    return NULL;
  }

  return filp;
}

void file_close(struct file *file) { filp_close(file, NULL); }

int file_read(struct file *file, unsigned long long offset, unsigned char *data,
              unsigned int size) {
  // TODO: Treat this buffer better and wait for all read
  int bytes_read = kernel_read(file, data, size, &offset);
  return bytes_read;
}

int file_write(struct file *file, unsigned long long offset,
               unsigned char *data, unsigned int size) {
  // TODO: Wait for all write
  int bytes_written = kernel_write(file, data, size, &offset);
  return bytes_written;
}
