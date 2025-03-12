# Simple project using Linux's Workqueue

Idea: Create a device ` Writable | Readable ` that calls a Workqueue whenever anyone tries to write to read it.

The Workqueue job is to write to a file whose value is written to the char device. Like a ping pong:

```bash
user@kernel:~$ echo "~/mypong.txt ping" >> /sys/dev/pong
user@kernel:~$ cat ~/mypong.txt
ping:pong
```

# Build and installation

```bash
sudo make;
sudo inmod pong_core.ko; # This installs driver
```

# Usage

```bash
sudo cat /dev/etx_device;
sudo dmesg;
```

# Remove from Kernel modules

```bash
sudo rmmod pong_core.ko
```

# Resources

1. [File Managment](https://docs.kernel.org/filesystems/files.html) 
2. [Full Driver Creation](https://embetronicx.com/tutorials/linux/device-drivers/work-queue-in-linux-own-workqueue/)
3. [Char Device Creation](https://tldp.org/LDP/lkmpg/2.4/html/c577.htm) 
4. [Workqueue](https://www.oreilly.com/library/view/understanding-the-linux/0596005652/ch04s08.html)
5. [Makefile](https://lwn.net/Articles/21835/) 
