
obj-m += hello.o


KDIR = /usr/src/linux-headers-3.11.0-26-generic/

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod *.symvers *.order	
