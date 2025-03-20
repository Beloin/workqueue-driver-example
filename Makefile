obj-m += pong_core.o

# Force same module linkage
pong_core-objs += pong_main.o

pong_core-objs += lib/device_setup.o lib/workqueue_setup.o
pong_core-objs += src/internalwq.o #src/file_utils.o

KDIR = /lib/modules/$(shell uname -r)/build
# KDIR = /lib/modules/6.10.13-3-MANJARO/build

KBUILD_CFLAGS += -I$(PWD)/include
KBUILD_CFLAGS += -I$(PWD)/lib

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
