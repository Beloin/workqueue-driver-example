# Simple project using Linux's Workqueue

Idea: Create a device ` Writable | Readable ` that calls a Workqueue whenever anyone tries to write to read it.

# Build and installation

```bash
sudo make;
sudo inmod driver.ko; # This installs driver
```

# Usage

```bash
sudo cat /dev/etx_device;
sudo dmesg;
```

# Resources

1. [File Managment](https://docs.kernel.org/filesystems/files.html) 
2. [Full Driver Creation](https://embetronicx.com/tutorials/linux/device-drivers/work-queue-in-linux-own-workqueue/)
