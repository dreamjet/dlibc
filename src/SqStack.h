typedef void* SqStack_ElemType;
typedef struct{
	SqStack_ElemType *data;
	int top;
	int length;
}SqStack;

SqStack* SqStack_new(SqStack_ElemType *data,int length);
void SqStack_push(SqStack *s,SqStack_ElemType *e);
SqStack_ElemType* SqStack_pop(SqStack *s);
SqStack_ElemType* SqStack_peek(SqStack *s);
int SqStack_isEmpty(SqStack *s);
int SqStack_isFull(SqStack *s);
