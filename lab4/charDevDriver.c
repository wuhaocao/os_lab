#include "charDevDriver.h"
#include "DriverFileOperation.h"

MODULE_LICENSE("GPL");

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = DriverOpen,
	.release = DriverRelease,
	.read = DriverRead,
	.write = DriverWrite,
};

static int __init charMsgDriverInit(void)
{	
	majorNumber = register_chrdev(0, "charMsgDriver", &fops);
	pcharMsgDriverClass = class_create(THIS_MODULE, "charMsgDriver");
	pCharMsgDriverDevice = device_create(pcharMsgDriverClass, NULL, MKDEV(majorNumber, 0), NULL, "charMsgDriver");
	return 0;
}

static void __exit charMsgDriverExit(void)
{
	unregister_chrdev(majorNumber, "charMsgDriver");
	device_unregister(pCharMsgDriverDevice);
	class_destroy(pcharMsgDriverClass);
}

module_init(charMsgDriverInit);
module_exit(charMsgDriverExit);
