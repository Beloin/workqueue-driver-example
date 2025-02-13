pong-objs := lib/device_setup.o lib/workqueue_setup.o
pong-objs := src/internalwq.o # src/file_utils.o
obj-m += pong.o

KDIR = /lib/modules/$(shell uname -r)/build
# KDIR = /lib/modules/6.10.13-3-MANJARO/build

EXTRA_CFLAGS+=-I$(PWD)/include
EXTRA_CFLAGS+=-I$(PWD)/lib

all:
	make -C $(KDIR)  M=$(shell pwd) modules

clean:
	make -C $(KDIR)  M=$(shell pwd) clean
