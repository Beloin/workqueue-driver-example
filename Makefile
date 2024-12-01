obj-m += driver.o
 
KDIR = /lib/modules/$(shell uname -r)/build

EXTRA_CFLAGS=-I$(PWD)/include

all:
	make -C $(KDIR)  M=$(shell pwd) modules

clean:
	make -C $(KDIR)  M=$(shell pwd) clean
