#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int help();
int quit();


static pDateNode head[] =
{
		{"help", "This is help infomation!", help, &head[1]},
		{"version", "Menu Program for lab3", help, &head[2]},
		{"setting", "This is setting function", help, &head[3]},
		{"quit","Quit", quit, NULL}
};

int main()
{
		while(1)
		{
				char cmd[CMD_MAX_LEN];
				printf("please input the cmd > ");
				scanf("%s", cmd);
				pDateNode *p = findCmd(head, cmd);
				if(p == NULL)					
		 		{					
						printf("ERROR:cmd not found!\n");
						continue;			
				}
				printf("%s : %s \n", p->cmd,p->desc);					
		 		if(p->handler != NULL)								
		 		{													
			  			p->handler();									
				}														
	 	}
}

int help()
{
		showAllCmd(head);
		return 0;
}

int quit()
{
		exit(0);
}
