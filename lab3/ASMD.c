#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

int ASMD_Operation(int* result, int num1, int num2, char* op)
{
	if(op)
        {
                if(*op == '+')
                        *result = num1 + num2;
                else if(*op == '-')
                        *result = num1 - num2;
                else if(*op == '*')
                        *result = num1 * num2;
                else if(*op == '/')
                {
                        if(num2 != 0)
                                *result = num1 / num2;
                        else
                                printk("divided number can't be zero.\n");
                }
        }
        else
        {
                printk("operator is empty.\n");
        }
        return 0;

}

int (*fptr_Operation)(int*, int, int, char*);

static int ASMD_init(void)
{	
	printk(KERN_INFO "Hello, kernel\n");
	fptr_Operation = &ASMD_Operation;
	return 0;
}

static void ASMD_exit(void)
{
	printk(KERN_INFO "Goodbye, kernel\n");
}

EXPORT_SYMBOL(fptr_Operation);

module_init(ASMD_init);
module_exit(ASMD_exit);
