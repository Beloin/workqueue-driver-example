obj-m += driver.o
 
KDIR = /lib/modules/6.10.13-3-MANJARO/build

all:
	make -C $(KDIR)  M=$(shell pwd) modules

clean:
	make -C $(KDIR)  M=$(shell pwd) clean
