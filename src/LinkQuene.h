typedef int LinkQuene_ElemType;
typedef struct LinkQuene_Node{
	LinkQuene_ElemType data;
	struct LinkQuene_Node* next;
}LinkQuene_Node;
typedef struct
{
	LinkQuene_Node *front,*rear;
}LinkQuene;

LinkQuene* LinkQuene_new();
void LinkQuene_enQuene(LinkQuene *q,LinkQuene_ElemType* e);
LinkQuene_ElemType* LinkQuene_deQuene(LinkQuene *q);
int LinkQuene_isEmpty(LinkQuene *q);
