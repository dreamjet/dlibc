#include "LinkStack.h"
#include <stdlib.h>

LinkStack* LinkStack_new(int length) {
	LinkStack* new = (LinkStack*) malloc(sizeof(LinkStack));
	new->count = 0;
	new->top = NULL;
	return new;
}

void LinkStack_push(LinkStack *s, LinkStack_ElemType *e) {
	LinkStack_Node* new = (LinkStack_Node*) malloc(sizeof(LinkStack_Node));
	new->data = *e;
	new->next = s->top;
	s->top = new;
	s->count++;
}

LinkStack_ElemType* LinkStack_pop(LinkStack *s) {
	LinkStack_Node* p;
	p = s->top;
	s->top = s->top->next;
	LinkStack_ElemType* e = &(p->data);
	free(p);
	return e;
}

LinkStack_ElemType* LinkStack_peek(LinkStack *s) {
	return &(s->top->data);
}

int LinkStack_isEmpty(LinkStack *s) {
	if (s->top == NULL) {
		return 1;
	} else {
		return 0;
	}
}
