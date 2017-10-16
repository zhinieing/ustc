#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#include <pthread.h>
#define SUCCESS 0
#define FAILURE (-1)
  
typedef struct LinkTableNode {
		    struct LinkTableNode * pNext;
}LinkTableNode;
  
typedef struct LinkTable {
		    LinkTableNode * pHead;
			    LinkTableNode * pTail;
				    int SumOfNode;
					    pthread_mutex_t mutex;
}LinkTable;
  
LinkTable * CreateLinkTable();
  
int DelLinkTable(LinkTable * pLinkTable);
  
int AddLinkTableNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode);
  
int DelLinkTableNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode);
 
LinkTableNode * GetLinkTableHeadNode(LinkTable * pLinkTable);
  
LinkTableNode * GetLinkTableNextNode(LinkTable * pLinkTable, LinkTableNode * pLinkTableNode);
  
#endif
