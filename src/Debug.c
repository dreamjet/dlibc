#include <stdlib.h>
#include <stdio.h>

void Debug_printIntArray(int* arr,int length,char* title){
	int i = 0;
	printf("IntArrayContent:%s\n",title);
	for(i=0;i<length;i++){
		printf("  index:%d  value:%d\n",i,arr[i]);
	}
}

/*void Debug_printSqList(SqList* l,char* title){
	int length = SqList_length(l);
	int i;
	printf("SqListContent:%s\n",title);
	for(i=0;i<length;i++){
		printf("  index:%d  value:%d\n",i,arr[i]);
	}
}*/

