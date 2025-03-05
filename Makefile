obj-m += pong.o

# Force same module linkage
pong-y += pong_main.o

# pong-y += src/internalwq.o lib/device_setup.o lib/workqueue_setup.o
obj-m += src/
obj-m += lib/

KDIR = /lib/modules/$(shell uname -r)/build
# KDIR = /lib/modules/6.10.13-3-MANJARO/build

EXTRA_CFLAGS += -I$(PWD)/include
EXTRA_CFLAGS += -I$(PWD)/lib

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
