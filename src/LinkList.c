#include "LinkList.h"
#include <stdlib.h>

LinkList* LinkList_new() {
	LinkList* l = (LinkList*) malloc(sizeof(LinkList));
	l->size = 0;
	l->next = NULL;
	return l;
}

LinkList_ElemType* LinkList_get(LinkList *l, int i) {
	int j;
	LinkList_Node *p;
	p = l->next;
	j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return &(p->data);
}

LinkList_ElemType* LinkList_set(LinkList *l, int i, LinkList_ElemType* e) {
	int j;
	LinkList_Node *p, *q;
	p = l->next;
	j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	q = p->next;
	LinkList_ElemType* e0 = &(q->data);
	q->data = *e;
	return e0;
}

void LinkList_insert(LinkList *l, int i, LinkList_ElemType* e) {
	int j;
	LinkList_Node *p, *new;
	p = l->next;
	j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	new = (LinkList_Node*) malloc(sizeof(LinkList_Node));
	new->data = *e;
	new->next = p->next;
	p->next = new;
	l->size++;
}

LinkList_ElemType* LinkList_remove(LinkList *l, int i) {
	int j;
	LinkList_Node *p, *q;
	p = l->next;
	j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	LinkList_ElemType* e = &(q->data);
	free(q);
	q=NULL;
	l->size--;
	return e;
}

void LinkList_clear(LinkList *l, void (*ElemType_free)(LinkList_ElemType*)) {
	LinkList_Node *p, *q;
	p = l->next;
	while (p != NULL) {
		q = p->next;
		ElemType_free(p->data);
		p->data=NULL;
		free(p);
		p = NULL;
		p = q;
	}
	l->next = NULL;
}

int LinkList_size(LinkList *l) {
	/*LinkList_Node *p;
	p = l->next;
	int size = 0;
	while (p != NULL) {
		p = p->next;
		size++;
	}*/
	return l->size;
}

