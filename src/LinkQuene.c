#include "LinkQuene.h"
#include <stdlib.h>

LinkQuene* LinkQuene_new(){
	LinkQuene* new = (LinkQuene*)malloc(sizeof(LinkQuene));
	LinkQuene_Node* head = (LinkQuene_Node*) malloc(sizeof(LinkQuene_Node));
	new->front = head;
	new->rear = head;
	return new;
}

void LinkQuene_enQuene(LinkQuene *q, LinkQuene_ElemType* e) {
	LinkQuene_Node* new = (LinkQuene_Node*) malloc(sizeof(LinkQuene_Node));
	new->data = *e;
	new->next = NULL;
	q->rear->next = new;
	q->rear = new;
}

LinkQuene_ElemType* LinkQuene_deQuene(LinkQuene *q) {
	LinkQuene_Node* p;
	p = q->front->next;
	LinkQuene_ElemType* e = &(p->data);
	q->front->next = p->next;
	free(p);
	return e;
}

int LinkQuene_isEmpty(LinkQuene *q){
	if(q->front==q->rear){
		return 1;
	}else{
		return 0;
	}
}
