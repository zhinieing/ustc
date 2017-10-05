#include<stdio.h>
#include<stdlib.h>

typedef struct DataNode
{
		char* cmd;
		char* desc;
		int (*handler)();
		struct DataNode *next;
}pDateNode;

pDateNode *findCmd(pDateNode *head,char *cmd);

int showAllCmd(pDateNode *head);
