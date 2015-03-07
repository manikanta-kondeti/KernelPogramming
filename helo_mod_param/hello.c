#include<linux/init.h>
#include<linux/module.h>
// Adding parameters 
#include<linux/moduleparam.h>

int param_val=0;

module_param(param_val, int , S_IRUSR | S_IWUSR);

void display_val()
{
	printk(KERN_ALERT "Values passed as parameter = %d\n",param_val);
	return;
}

//No scanf and printf, instead use printk, it writes into file, we can use dmesg
static int hello_init(void)
{
	printk(KERN_ALERT "HelloWorld, My first written kernel module. I'm very excited to learn this stuff\n");
	display_val();
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT  "Done with my first module, Bbye :D :D\n");
	return;
}


module_init(hello_init);

module_exit(hello_exit);
