#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

LinkTable * CreateLinkTable()
{
		    LinkTable * pLinkTable = (LinkTable *)malloc(sizeof(LinkTable));
			    if (pLinkTable == NULL)
						    {
									        return NULL;
											    }
				    pLinkTable->pHead = NULL;
					    pLinkTable->pTail = NULL;
						    pLinkTable->SumOfNode = 0;
							    return pLinkTable;
}
    
int DelLinkTable(LinkTable * pLinkTable)
{
		    if (pLinkTable == NULL)
					    {
								        return FAILURE;
										    }
			    while (pLinkTable->pHead != NULL)
						    {
									        LinkTableNode * p = pLinkTable->pHead;
											        pLinkTable->pHead = pLinkTable->pHead->pNext;
													        free(p);
															        pLinkTable->SumOfNode --;
																	    }
				    pLinkTable->pHead = NULL;
					    pLinkTable->pTail = NULL;
						    pLinkTable->SumOfNode = 0;
							    free(pLinkTable);
								    return SUCCESS;
}
    
int AddLinkTableNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode)
{
		    if (pLinkTable == NULL || pLinkTableNode == NULL)
					    {
								        return FAILURE;
										    }
			    if (pLinkTable->pHead == NULL)
						    {
									        pLinkTable->pHead = pLinkTableNode;
											    }
				    if (pLinkTable->pTail == NULL)
							    {
										        pLinkTable->pTail = pLinkTableNode;
												    }
					    else 
								    {
											        pLinkTable->pTail->pNext = pLinkTableNode;
													        pLinkTable->pTail = pLinkTableNode;
															        pLinkTable->pTail->pNext = NULL;
																	    }
						    pLinkTable->SumOfNode++;
							    return SUCCESS;
}
    
int DelLinkTableNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode)
{
		    if (pLinkTable == NULL || pLinkTableNode == NULL)
					    {
								        return FAILURE;
										    }
			    if (pLinkTable->pHead == pLinkTableNode)
						    {
									        pLinkTable->pHead = pLinkTable->pHead->pNext;
											        pLinkTable->SumOfNode--;
													        if (pLinkTable->SumOfNode == 0)
																	        {
																					            pLinkTable->pTail = NULL;
																								        }
															        return SUCCESS;
																	    }
				    LinkTableNode * pTemp = pLinkTable->pHead;
					    while (pTemp != NULL)
								    {
											        if (pTemp->pNext == pLinkTableNode)
															        {
																			            pTemp->pNext = pTemp->pNext->pNext;
																						            pLinkTable->SumOfNode--;
																									            if (pLinkTable->SumOfNode == 0)
																														            {
																																			                pLinkTable->pTail = NULL;
																																							            }
																												            return SUCCESS;
																															        }
													        pTemp = pTemp->pNext;
															    }
						    return FAILURE;
}
   
LinkTableNode * GetLinkTableHeadNode(LinkTable * pLinkTable)
{
		    if (pLinkTable == NULL || pLinkTable->pHead == NULL)
					    {
								        return NULL;
										    }
			    return pLinkTable->pHead;
}

LinkTableNode * GetLinkTableNextNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode)
{
		    if (pLinkTable == NULL || pLinkTableNode == NULL)
					    {
								        return NULL;
										    }
			    LinkTableNode * pTemp = pLinkTable->pHead;
				    while (pTemp != NULL)
							    {
										        if (pTemp == pLinkTableNode)
														        {
																		            return pTemp->pNext;
																					        }
												        pTemp = pTemp->pNext;
														    }
					    return NULL;
}
