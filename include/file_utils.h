////////////////////////////////////////////////////////////////////////////////
// File:        file_utils.h
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <linux/fs.h>

struct file *file_open(const char *path, int flags, int rights);

void file_close(struct file *file);

int file_read(struct file *file, unsigned long long offset, unsigned char *data,
              unsigned int size);

int file_write(struct file *file, unsigned long long offset,
               unsigned char *data, unsigned int size);

#endif /* FILE_UTILS_H */
