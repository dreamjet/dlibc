typedef void* LinkList_ElemType;
typedef struct LinkList_Node
{
	LinkList_ElemType data;
	struct LinkList_Node *next;
}LinkList_Node;
typedef struct LinkList
{
	struct LinkList_Node *next;
	int size;
}LinkList;

LinkList* LinkList_new();
LinkList_ElemType* LinkList_get(LinkList *l,int i);
void LinkList_insert(LinkList *l, int i, LinkList_ElemType* e);
LinkList_ElemType* LinkList_remove(LinkList *l, int i);
LinkList_ElemType* LinkList_set(LinkList *l, int i, LinkList_ElemType* e);
void LinkList_clear(LinkList *l, void (*ElemType_free)(LinkList_ElemType*));
int LinkList_size(LinkList *l);
