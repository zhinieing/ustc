#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

pDateNode *findCmd(pDateNode *head, char *cmd)
{
		if(head == NULL || cmd == NULL)
		{
				return NULL;
		}
		pDateNode *p = head;
		while(p != NULL)
		{
				if(!strcmp(p->cmd, cmd))
				{																		            return p;
				}
				p = p->next;
		}
		return NULL;
}

int showAllCmd(pDateNode *head)
{
		printf("Menu List:\n");
		pDateNode *p = head;
		while(p != NULL)
		{
				printf("%s\n",p->cmd);
				p = p->next;
		}
		return 0;
}
