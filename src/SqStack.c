#include "SqStack.h"
#include <stdlib.h>

SqStack* SqStack_new(SqStack_ElemType *data,int length){
	SqStack* s = (SqStack*) malloc(sizeof(SqStack));
	/*SqStack_ElemType temp[length];
	s->data = temp;*/
	s->data = data;
	s->top = -1;
	s->length = length;
	return s;
}

void SqStack_push(SqStack *s, SqStack_ElemType *e) {
	s->top++;
	s->data[s->top] = *e;
}

SqStack_ElemType* SqStack_pop(SqStack *s) {
	SqStack_ElemType* e = &(s->data[s->top]);
	s->top--;
	return e;
}

SqStack_ElemType* SqStack_peek(SqStack *s){
	return &(s->data[s->top]);
}

int SqStack_isEmpty(SqStack *s){
	if(s->top==-1){
		return 1;
	}else{
		return 0;
	}
}

int SqStack_isFull(SqStack *s){
	if(s->top==s->length-1){
			return 1;
		}else{
			return 0;
	}
}


