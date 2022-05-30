obj-m := charMsgModule.o
charMsgModule-objs := charDevDriver.o DriverFileOperation.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	rm *.order *.mod.c *.o *.symvers
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

