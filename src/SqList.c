#include "SqList.h"
#include "Debug.h"
#include <stdlib.h>

SqList* SqList_new(SqList_ElemType *data, int length) {
	SqList* l = (SqList*) malloc(sizeof(SqList));
	l->data = data;
	l->length = length;
	return l;
}

SqList_ElemType* SqList_get(SqList *l, int i) {
	return &(l->data[i]);
}

SqList_ElemType* SqList_setCopy(SqList *l, int i, SqList_ElemType *e) {
	SqList_ElemType* e0 = &(l->data[i]);
	l->data[i] = *e;
	return e0;
}

void SqList_clear(SqList *l, void (*ElemType_free)(SqList_ElemType*)) {
	int i;
	for (i = 0; i < SqList_length(l); i++) {
		ElemType_free(l->data[i]);
		l->data[i] = NULL;
	}
}

int SqList_length(SqList *l) {
	return l->length;
}

void SqList_swap(SqList *l, int i, int j) {
	SqList_ElemType temp;
	temp = *SqList_get(l, i);
	SqList_setCopy(l, i, SqList_get(l, j));
	SqList_setCopy(l, j, &temp);
}

void SqList_bubbleSort(SqList *l,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int length = SqList_length(l);
	int j = length - 1;
	int i = 0;
	int k;
	while (i != j) {
		for (k = j; k > i; k--) {
			if (ElemType_compare(SqList_get(l, k), SqList_get(l, k - 1)) < 0) {
				SqList_swap(l, k, k - 1);
			}
		}
		i++;
	}
}

void SqList_insertSort(SqList *l,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int length = SqList_length(l);
	int i, j;
	SqList_ElemType t;
	for (i = 1; i < length; i++) {
		t = *SqList_get(l, i);
		j = i - 1;
		while (j >= 0 && ElemType_compare(&t, SqList_get(l, j)) < 0) {
			SqList_setCopy(l, j + 1, SqList_get(l, j));
			j--;
		}
		SqList_setCopy(l, j + 1, &t);
	}
}

void SqList_shellSort(SqList *l,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*),
		int (*func)(int)) {
	int i, j, gap;
	int len = SqList_length(l);
	SqList_ElemType t;
	gap = func(len);
	while (gap > 0) {
		for (i = gap; i < len; i++) {
			t = *SqList_get(l, i);
			j = i - gap;
			while (j >= 0 && ElemType_compare(&t, SqList_get(l, j)) < 0) {
				SqList_setCopy(l, j + gap, SqList_get(l, j));
				j = j - gap;
			}
			SqList_setCopy(l, j + gap, &t);
		}
		gap = func(gap);
	}
}

void SqList_quickSort(SqList *l, int fromIndex, int toIndex,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int i = fromIndex;
	int j = toIndex;
	SqList_ElemType t;
	t = *SqList_get(l, i);
	if (fromIndex < toIndex) {
		while (i != j) {
			while (j > i && ElemType_compare(SqList_get(l, j), &t) >= 0) {
				j--;
			}
			SqList_setCopy(l, i, SqList_get(l, j));
			while (j > i && ElemType_compare(SqList_get(l, i), &t) <= 0) {
				i++;
			}
			SqList_setCopy(l, j, SqList_get(l, i));
		}
		SqList_setCopy(l, i, &t);
		SqList_quickSort(l, fromIndex, i - 1, ElemType_compare);
		SqList_quickSort(l, i + 1, toIndex, ElemType_compare);
	}
}

void SqList_selectSort(SqList *l,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int i, j, k;
	int len = SqList_length(l);
	for (i = 0; i < len - 1; i++) {
		k = i;
		for (j = i + 1; j < len; j++) {
			if (ElemType_compare(SqList_get(l, k), SqList_get(l, j)) > 0) {
				k = j;
			}
		}
		if (k != i) {
			SqList_swap(l, i, k);
		}
	}
}

int SqList_BFIndex(SqList *l, SqList *key, int fromIndex,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int i = fromIndex;
	int j = 0;
	while (i < SqList_length(l) && j < SqList_length(key)) {
		if (ElemType_compare(SqList_get(l, i), SqList_get(key, j)) == 0) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == SqList_length(key)) {
		return i - SqList_length(key);
	} else {
		return -1;
	}
}

void SqList_KMPBuildNextArray(SqList *l, int *next,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int length = SqList_length(l);
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	while (j < length - 1) {
		if (k == -1
				|| ElemType_compare(SqList_get(l, j), SqList_get(l, k)) == 0) {
			j++;
			k++;
			next[j] = k;
		} else
			k = next[k];
	}
}

int SqList_KMPIndex(SqList *l, SqList *key, int fromIndex,
		int (*ElemType_compare)(SqList_ElemType*, SqList_ElemType*)) {
	int lL = SqList_length(l);
	int kL = SqList_length(key);
	int next[kL];
	SqList_KMPBuildNextArray(key, next, ElemType_compare);
	int i = fromIndex;
	int j = 0;
	while (i < lL && j < kL) {
		if (j == -1
				|| ElemType_compare(SqList_get(l, i), SqList_get(key, j))
						== 0) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j == kL) {
		return i - kL;
	} else {
		return -1;
	}
}
