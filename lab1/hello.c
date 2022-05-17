#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static char* whom;
module_param(whom, charp, S_IRUGO);

static int num;
module_param(num, int, S_IRUGO);

static int __init hello_init(void)
{
    int i;

    printk(KERN_INFO "whom = %s\n", whom);

    printk(KERN_INFO "num = %d\n", num);

    for(i = 0; i < num; i++)
    {
        printk(KERN_INFO "Hello, %s\n", whom);
    }

    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye, kernel\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("whc");
MODULE_LICENSE("GPL v2");

