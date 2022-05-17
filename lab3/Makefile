obj-m += ASMD.o call_ASMD.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
modules:
	rm *.order *.mod.c *.o *.symvers
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
