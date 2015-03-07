obj-m += module_param.o

KDIR = /usr/src/linux-headers-3.11.0-26-generic

all:
	   $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	  rm -rf module_param.ko module_param.o

