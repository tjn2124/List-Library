#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "mylist.h"


struct Node *addFront(struct List *list, void *xNode){
	struct Node *node1 = malloc(sizeof(struct Node));
	if(!node1) return NULL;
	if (node1 == NULL) {
		perror("malloc returned NULL");
		exit(1);
       	}
	node1->data = xNode;

	node1->next = list->head;
	list->head= node1;

	return node1;
}


void traverseList(struct List *list, void (*f)(void *)){
	struct Node *node = list->head;
	while(node!=NULL){
		f(node->data);
		node = node->next;
	}	
}

void flipSignDouble(void *data){
	double x = *(double *)data; 
	double y =(-1*(x));
	void *z = (void *)&y;
	memcpy(data, z, sizeof(double));
}


int compareDouble(const void *data1, const void *data2){
	double x = *(double *) data1;
	double y = *(double *) data2;
	if (x==y){
	       return 0;
	}
	return 1;
}


struct Node *findNode(struct List *list, const void *dataSought, int (*compar)(const void *, const void *)){
	struct Node *node = node = list->head;
	while(node!=NULL){
		int b = compar(dataSought, node->data);
		if (b == 0){
			return node;
		}
		else{
			node = node->next;
		}
	}
	return NULL;

}

void *popFront(struct List *list){
	if(isEmptyList(list)){
		return NULL;
	}
	struct Node *node = list->head;
	list->head = node->next;
	void *d = node->data;
	free(node);
	return d;
}

void removeAllNodes(struct List *list){
	struct Node *node = list->head;
	while(!isEmptyList(list) && node != NULL){
		popFront(list);
	}
}

struct Node *addAfter(struct List *list,struct Node *prevNode, void *data){//(&list, node, a+i)
	
	struct Node *newNode = malloc(sizeof(struct Node));
	if(!newNode) return NULL;
	newNode -> data = data;

	struct Node *node = list->head;
	
	
	while(node!=NULL){
		if (node->data==prevNode->data){
			newNode->next= node->next;
			node->next = newNode;
			return newNode;
		}
		node = node->next;
	}

	free(newNode);
	return addFront(list, data);
}
void reverseList(struct List *list){
	 struct Node *prv = NULL;
	 struct Node *cur = list->head;
	 struct Node *nxt;
	 while (cur) {
		 nxt = cur->next;
		 cur->next = prv;
		 prv = cur;
		 cur = nxt;
	 }
	 list->head = prv;
 }
