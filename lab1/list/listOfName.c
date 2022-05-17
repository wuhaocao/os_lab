#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct name
{
    struct list_head list;
    char *s;
};

struct name headnode;

static int __init listOfName_init(void)
{
    struct name *listnode;
    struct list_head *pos;
    struct name *p;

    INIT_LIST_HEAD(&headnode.list);

    listnode = (struct name *)kmalloc(sizeof(struct name),GFP_KERNEL);
    listnode->s = "cao";
    list_add_tail(&listnode->list, &headnode.list);

    listnode = (struct name *)kmalloc(sizeof(struct name),GFP_KERNEL);
    listnode->s = "wu";
    list_add_tail(&listnode->list, &headnode.list);

    listnode = (struct name *)kmalloc(sizeof(struct name),GFP_KERNEL);
    listnode->s = "hao";
    list_add_tail(&listnode->list, &headnode.list);

    list_for_each(pos, &headnode.list)
    {   
        p = list_entry(pos, struct name, list);
        printk("%s\n", p->s);
    }

    return 0;

}

static void __exit listOfName_exit(void)
{
    struct list_head *pos, *n;
    struct name *p;

    list_for_each_safe(pos, n, &headnode.list)
    {
        list_del(pos);
        p = list_entry(pos, struct name, list);
        kfree(p);
    }
    printk("Goodbye, kernel\n");
}

module_init(listOfName_init);
module_exit(listOfName_exit);

MODULE_AUTHOR("whc");
MODULE_LICENSE("GPL v2");
