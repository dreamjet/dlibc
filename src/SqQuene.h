typedef void* SqQuene_ElemType;
typedef struct {
	SqQuene_ElemType *data;
	int front;
	int rear;
	int length;
}SqQuene;

SqQuene* SqQuene_new(SqQuene_ElemType *data,int length);
void SqQuene_enQuene(SqQuene *q,SqQuene_ElemType *e);
SqQuene_ElemType* SqQuene_deQuene(SqQuene *q);
int SqQuene_isEmpty(SqQuene *q);
int SqQuene_isFull(SqQuene *q);
