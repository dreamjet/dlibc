typedef void* SqList_ElemType;
typedef struct SqList
{
	SqList_ElemType *data;
	int length;
}SqList;

SqList* SqList_new(SqList_ElemType *data,int length);
//SqList* SqList_newFromIntArray(int ,int length);
SqList_ElemType* SqList_get(SqList *l, int i);
SqList_ElemType* SqList_setCopy(SqList *l, int i, SqList_ElemType * e);
void SqList_clear(SqList *l,void (*ElemType_free)(SqList_ElemType*));
int SqList_length(SqList *l);
void SqList_swap(SqList *l,int i,int j);

//void SqList_sort(SqList *l,int (*ElemType_compare)(SqList_ElemType*,SqList_ElemType*));
void SqList_insertSort(SqList *l,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
void SqList_shellSort(SqList *l,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*),int (*func)(int));
void SqList_quickSort(SqList *l,int fromIndex,int toIndex,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
void SqList_selectSort(SqList *l,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
void SqList_bubbleSort(SqList *l,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
void SqList_KMPBuildNextArray(SqList *l,int *next,int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
int SqList_BFIndex(SqList *l, SqList *key, int fromIndex,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
int SqList_KMPIndex(SqList *l, SqList *key, int fromIndex,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*));
