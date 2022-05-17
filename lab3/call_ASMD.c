#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

extern int (*fptr_Operation)(int*, int, int, char*);

static int call_ASMD_init(void)
{
	int count = 10000 * 10000;
	printk("count is: %d\n", count);
        struct timeval tstart, tend;
        do_gettimeofday(&tstart);
        int i;
        int result;
        int times = count / 4;
        for(i = 0; i < times; ++i)
        {
                char op_add = '+';
                fptr_Operation(&result, 10, 10, &op_add);
        }
        printk("ASMD_Operation op_add is ok. op_add count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_sub = '-';
                fptr_Operation(&result, 20, 10, &op_sub);
        }
        printk("ASMD_Operation op_sup is ok. op_sup count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_mul = '*';
                fptr_Operation(&result, 10, 10, &op_mul);
        }
        printk("ASMD_Operation op_mul is ok. op_mul count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_div = '/';
                fptr_Operation(&result, 20, 10, &op_div);
        }
        printk("ASMD_Operation op_div is ok. op_div count is: %d\n", i);

        do_gettimeofday(&tend);
        printk("ASMD_Operation running time is %ld usec\n", 1000000 * (tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec));

        return 0;
}

static void call_ASMD_exit(void)
{
	printk(KERN_INFO "Goodbye, kernel\n");
}

module_init(call_ASMD_init);
module_exit(call_ASMD_exit);
