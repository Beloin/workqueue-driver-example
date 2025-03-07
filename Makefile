obj-m += pong_core.o

# Force same module linkage
pong_core-y := pong_main.o

obj-y += src/
obj-y += lib/

KDIR = /lib/modules/$(shell uname -r)/build
# KDIR = /lib/modules/6.10.13-3-MANJARO/build

EXTRA_CFLAGS += -I$(PWD)/include
EXTRA_CFLAGS += -I$(PWD)/lib

all:
	make -C $(KDIR) M=$(shell pwd) modules

clean:
	make -C $(KDIR) M=$(shell pwd) clean
