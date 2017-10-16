#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
int Help();
int Quit();
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define MENU_NUM 10
typedef struct DataNode
{
		    LinkTableNode* next;
			    char* cmd;
				    char* desc;
					    int(*handler)();
}DataNode;
DataNode* FindCmd(LinkTable * head, char * cmd)
{
		    if (head == NULL || cmd == NULL)
					    {
								        return NULL;
										    }
			    DataNode * p = (DataNode *)GetLinkTableHeadNode(head);
				    while (p != NULL)
							    {
										        if (strcmp(p->cmd, cmd) == 0)
														        {
																		            return p;
																					        }
												        p = (DataNode *)GetLinkTableNextNode(head, (LinkTableNode *) p );
														    }
					    return NULL;
}


int ShowAllCmd(LinkTable* head)
{
		    printf("Menu List:\n");
			    DataNode* p = (DataNode *)GetLinkTableHeadNode(head);
				    printf("+----------+---------------------------------+\n");
					    while (p != NULL)
								    {
											        printf("+ %-8s +  %-32s\n", p->cmd, p->desc);
													        p = (DataNode *)GetLinkTableNextNode(head, (LinkTableNode *)p);
															    }
						    printf("+----------+---------------------------------+\n");
							    return 0;
}

int InitMenuData(LinkTable ** ppLinkTable)
{
		    *ppLinkTable = CreateLinkTable();
			    DataNode * p = (DataNode *)malloc(sizeof (DataNode));
				    p->cmd = "help";
					    p->desc = "Menu List:\n";
						    p->handler = Help;
							    AddLinkTableNode(*ppLinkTable, (LinkTableNode *)p);
								    p = (DataNode *)malloc(sizeof (DataNode));
									    p->cmd = "version";
										    p->desc = "Menu Program V2.5\n";
											    p->handler = NULL;
												    AddLinkTableNode(*ppLinkTable, (LinkTableNode*)p);
													    p = (DataNode *)malloc(sizeof (DataNode));   
														    p->cmd = "quit";
															    p->desc = "Quit from menu\n";
																    p->handler = Quit;
																	    AddLinkTableNode(*ppLinkTable, (LinkTableNode *)p);
																			return 0;
}

LinkTable *head = NULL;
int main()
{
		    //cmd line begins
		    InitMenuData(&head);
			    while (1)
						    {
									        char cmd[CMD_MAX_LEN];
											        printf("\nplease input a cmd >>");
													        scanf("%s", cmd);
															        DataNode* p = FindCmd(head, cmd);
																	        if (p == NULL)
																					        {
																									            printf("This is a wrong cmd! please input 'help' to learn more...\n");
																												            continue;
																															        }
																			        printf("%s --- %s", p->cmd, p->desc);
																					        if (p->handler != NULL)
																									        {
																													            p->handler();
																																        }
																							    }
				    return 0;
}

int Help()
{
	    ShowAllCmd(head);
		return 0;
}

int Quit()
{
		exit(0);
		return 0;
}
