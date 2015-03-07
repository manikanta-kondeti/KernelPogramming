obj-m += module2.o

KDIR = /usr/src/linux-headers-3.11.0-26-generic/

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)  modules

clean:
	rm -rf *.o  *.ko 
