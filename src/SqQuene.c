#include "SqQuene.h"
#include <stdlib.h>

SqQuene* SqQuene_new(SqQuene_ElemType* data,int length){
	SqQuene* new = (SqQuene*)malloc(sizeof(SqQuene));
	/*SqQuene_ElemType temp[length];
	new->data = temp;*/
	new->data = data;
	new->front = 0;
	new->rear = 0;
	return new;
}
void SqQuene_enQuene(SqQuene *q,SqQuene_ElemType *e){
		q->data[q->rear] = *e;
		q->rear = (q->rear+1)%q->length;
}
SqQuene_ElemType* SqQuene_deQuene(SqQuene *q){
	SqQuene_ElemType* e = &(q->data[q->front]);
	q->front = (q->front+1)%q->length;
	return e;
}
int SqQuene_isEmpty(SqQuene *q){
	if(q->front==q->rear){
		return 1;
	}else{
		return 0;
	}
}
int SqQuene_isFull(SqQuene *q){
	if(q->front == (q->rear+1)%q->length){
		return 1;
	}else{
		return 0;
	}
}

