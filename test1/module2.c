#include<linux/module.h>
#include<linux/init.h>

static int hello_check(void)
{
	printk(KERN_ALERT "This is module2 ....Checking secnod time\n");
	return 0;
}


static void exit_check(void)
{
	printk(KERN_ALERT "Module2 done...Lets start the show bitches\n");
	return;
}

module_init(hello_check);

module_exit(exit_check);
