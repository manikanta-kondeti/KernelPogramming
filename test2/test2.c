#include<linux/module.h>
#include<linux/init.h>

static int test2_hello(void)
{
	printk(KERN_ALERT  "Hello, I'm writing test2 \n");
	return 0;
}

static void test2_exit(void)
{
	printk(KERN_ALERT  "And its done, thanks for your anticipation \n");
	return;
}

module_init(test2_hello);

module_exit(test2_exit);
