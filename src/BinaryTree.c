#include <stdlib.h>
#include "BinaryTree.h"

BinaryTree* BinaryTree_new() {
	BinaryTree* t = (BinaryTree*) malloc(sizeof(BinaryTree));
	//t->depth = 0;
	return t;
}
/*BinaryTree* BinaryTree_newFromCharArray(char * str){

 }*/
/*BinaryTree_Node* BinaryTree_newNode(BinaryTree_ElemType * e) {
 BinaryTree_Node* node = (BinaryTree_Node*) malloc(sizeof(BinaryTree_Node));

 BinaryTree_ElemType * p = &(node->data);
 = e;
 return &node;
 }*/
BinaryTree_Node* BinaryTree_newNodeCopy(BinaryTree_ElemType * e) {
	BinaryTree_Node* node = (BinaryTree_Node*) malloc(sizeof(BinaryTree_Node));
	node->data = *e;
	return node;
}
BinaryTree_Node* BinaryTree_getRootNode(BinaryTree * bt) {
	return bt->root;
}
void BinaryTree_setRootNode(BinaryTree * bt, BinaryTree_Node * node) {
	bt->root = node;
}
BinaryTree_Node* BinaryTree_getLchild(BinaryTree_Node * p) {
	return p->lchild;
}
BinaryTree_Node* BinaryTree_getRchild(BinaryTree_Node * p) {
	return p->rchild;
}
void BinaryTree_setLchild(BinaryTree_Node * p, BinaryTree_Node * c) {
	p->lchild = c;
}
void BinaryTree_setRchild(BinaryTree_Node * p, BinaryTree_Node * c) {
	p->rchild = c;
}
static int BinaryTree_depthRootNode(BinaryTree_Node * n) {
	int ld, rd;
	if (n == NULL) {
		return 0;
	} else {
		ld = BinaryTree_depthRootNode(n->lchild);
		rd = BinaryTree_depthRootNode(n->rchild);
		return (ld > rd) ? (ld + 1) : (rd + 1);
	}
}
int BinaryTree_depth(BinaryTree * bt) {
	return BinaryTree_depthRootNode(BinaryTree_getRootNode(bt));
}
static void BinaryTree_preOrderRootNode(BinaryTree_Node * n) {
	if (n != NULL) {
		//do
		//end
		BinaryTree_preOrderRootNode(n->lchild);
		BinaryTree_preOrderRootNode(n->rchild);
	}
}
void BinaryTree_preOrder(BinaryTree * bt) {
	BinaryTree_preOrderRootNode(bt->root);
}
static void BinaryTree_inOrderRootNode(BinaryTree_Node * n) {
	if (n != NULL) {
		BinaryTree_preOrderRootNode(n->lchild);
		//do
		//end
		BinaryTree_preOrderRootNode(n->rchild);
	}
}
void BinaryTree_inOrder(BinaryTree * bt) {
	BinaryTree_inOrderRootNode(bt->root);
}
static void BinaryTree_postOrderRootNode(BinaryTree_Node * n) {
	if (n != NULL) {
		BinaryTree_postOrderRootNode(n->lchild);
		BinaryTree_postOrderRootNode(n->rchild);
		//do
		//end
	}
}
void BinaryTree_postOrder(BinaryTree * bt) {
	BinaryTree_postOrderRootNode(bt->root);
}

