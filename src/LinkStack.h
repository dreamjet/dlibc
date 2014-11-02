typedef void* LinkStack_ElemType;
typedef struct LinkStack_Node {
	LinkStack_ElemType data;
	struct LinkStack_Node *next;
} LinkStack_Node;
typedef struct LinkStack {
	LinkStack_Node* top;
	int count;
} LinkStack;

LinkStack* LinkStack_new(int length);
void LinkStack_push(LinkStack *s, LinkStack_ElemType *e);
LinkStack_ElemType* LinkStack_pop(LinkStack *s);
LinkStack_ElemType* LinkStack_peek(LinkStack *s);
int LinkStack_isEmpty(LinkStack *s);

