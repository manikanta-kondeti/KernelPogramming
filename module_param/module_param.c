#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

int param_val[5]={0};

module_param_array(param_val, int,NULL, S_IRUSR | S_IWUSR );

void sum_cal(void)
{
	printk(KERN_ALERT "sum=%d", param_val[0]+param_val[1]+param_val[2]+param_val[3]+param_val[4]);
         return;
}

static int hello_init(void)
{
printk(KERN_ALERT "Hey baby, module param file ;) calling function \n");
sum_cal();
return 0;
}


static void hello_exit(void)
{
printk(KERN_ALERT "Yo bitch! Hacking done :D\n");
return;
}

module_init(hello_init);
module_exit(hello_exit);
