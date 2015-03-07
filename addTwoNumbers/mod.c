#include<linux/module.h>
#include<linux/init.h>


static int addTwoNum(void)
{
	long int sum= 123+246;
	printk(KERN_ALERT "Okay, I'm gonna add two long integers..Stay Tuned bitches :D \n");
	printk(KERN_ALERT "And the answer is sum=369 \n");
	return 0;
}

static void fun_exit(void){
	printk(KERN_ALERT "*******Yeah its done****\n");
	return;
}


module_init(addTwoNum);
module_exit(fun_exit);
