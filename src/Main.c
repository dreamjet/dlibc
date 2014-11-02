/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "SqList.h"
#include "Debug.h"

int Int_compare(int* a, int* b) {
	return *a - *b;
}
int Int_f1(int a) {
	return a / 2;
}
int main(void) {
	int i = 0;
	int integer = 0;
	int* pInteger = &integer;

	int* list[10];
	//int next[10];
	SqList* listL = SqList_new((SqList_ElemType*) list, 10);

	integer = 4;
	for (i = 0; i < 10; i++) {
		//(*pInteger)++;
		SqList_setCopy(listL, i, (SqList_ElemType*) pInteger);
	}
	integer = 3;
	SqList_setCopy(listL, 0, (SqList_ElemType*) pInteger);
	integer = 0;
	SqList_setCopy(listL, 2, (SqList_ElemType*) pInteger);
	integer = 1;
	SqList_setCopy(listL, 6, (SqList_ElemType*) pInteger);
	/*SqList_shellSort(listL,
	 (int (*)(SqList_ElemType*, SqList_ElemType*)) Int_compare,Int_f1);
	 */
	/*SqList_quickSort(listL,0,9,
	 (int (*)(SqList_ElemType*, SqList_ElemType*)) Int_compare);
	 */
	SqList_selectSort(listL,
			(int (*)(SqList_ElemType*, SqList_ElemType*)) Int_compare);
	for (i = 0; i < 10; i++) {
		printf("  gg index:%d  value:%d\n", i, (int) *SqList_get(listL, i));
	}

	int* list2[3];
	//int next[10];
	SqList* list2L = SqList_new((SqList_ElemType*) list2, 3);
	integer = 4;
	for (i = 0; i < 3; i++) {
		//(*pInteger)++;
		SqList_setCopy(list2L, i, (SqList_ElemType*) pInteger);
	}

	int r = SqList_KMPIndex(listL, list2L, 0,
			(int (*)(SqList_ElemType*, SqList_ElemType*)) Int_compare);
	//int r = SqList_BFIndex(listL,list2L,0,(int (*)(SqList_ElemType* ,SqList_ElemType* ))Int_compare);
	//SqList_bubbleSort(listL,(int (*)(SqList_ElemType* ,SqList_ElemType* ))Int_compare);

	for (i = 0; i < 10; i++) {
		printf("debug3-%d-%d\n", i, (int) *SqList_get(listL, i));
	}

	printf("debugKMP-%d\n", r);
	//SqList_KMPBuildNextArray((SqList*) listL, next, (int (*)(SqList_ElemType* ,SqList_ElemType* ))Int_compare);

	/*for (i = 0; i < 10; i++) {
	 printf("debug2-%d-%d\n", i, next[i]);
	 }*/

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
