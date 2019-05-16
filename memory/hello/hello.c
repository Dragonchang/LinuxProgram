#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
//#include <linux/list.h>
//#include <linux/mm.h>
//#include "hello.h"
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/types.h>
#include <asm/pgtable.h>
#include <asm/page.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Gatieme");
MODULE_DESCRIPTION("hello world");

/*
 * print the module information
 */
void print_module(void)
{
    struct module *mod;

    printk(KERN_ALERT "this module: %p==%p\n", &__this_module, THIS_MODULE);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
    printk(KERN_ALERT "module name: %s\n", THIS_MODULE->name);

    list_for_each_entry(mod, *(&THIS_MODULE->list.prev), list);
    printk(KERN_ALERT "module name: %s\n", mod->name);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
    printk(KERN_EMERG "***********zfl-print_module --begin pid: %d, comm: %.20s\n",current->pid, current->comm);
}

long readPhysicsAddress(unsigned long pa, int *pStatus)
{
    long data = -1;
    data = *(long *)pa;
    printk(KERN_INFO "physics address : 0x%lx, data : 0x%lx", pa, data);

    return data;
}

long writePhysicsAddress(unsigned long pa, unsigned long data, int *pStatus)
{
    long oldData = -1;

    oldData = *(long *)pa;
    printk(KERN_INFO "physics address : 0x%lx, old data : 0x%lx", pa, *(long *)pa);

    *(long *)pa = data;
    printk(KERN_INFO "physics address : 0x%lx, new data : 0x%lx", pa, *(long *)pa);

    return oldData;
}

static unsigned long read_pgd(void)
{
    return (unsigned long)current->mm->pgd;
}

extern enum system_states system_state;

void virtual_addr_2_Phy(void) {

    int value = 10;
    // use virt_to_phys
    // http://lxr.free-electrons.com/source/arch/arm64/include/asm/memory.h?v4.7#L189

    unsigned long long phyaddr = virt_to_phys(18446744071562068000);
    printk("0x%lx\n", (unsigned long )phyaddr);
}

void test_pgd(void) {
    unsigned long cr3;
    unsigned long pgd = 0;

    printk("system_state = %d\n", system_state);

    cr3 = read_cr3();
    printk("cr3----------------->0x%lx\n", cr3);
    pgd = __pa(read_pgd());
    printk("pgd----------------->0x%lx\n", pgd);
}

EXPORT_SYMBOL(print_module);

int hello_init(void)
{
    print_module( );

    //readPhysicsAddress(0x1000000, NULL);

    printk(KERN_ALERT "run in cpu %d\n", get_cpu());

    printk(KERN_ALERT "PAGE_OFFSET : 0x%lx, TASK_SIZE : 0x%lx", PAGE_OFFSET, TASK_SIZE);

    virtual_addr_2_Phy();
    test_pgd();


    return 0;
}



void hello_exit(void)
{
    printk(KERN_ERR"exit");
}


module_init(hello_init);
module_exit(hello_exit);


