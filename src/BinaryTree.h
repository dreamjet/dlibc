typedef void* BinaryTree_ElemType;
typedef struct BinaryTree_Node
{
	BinaryTree_ElemType data;
	struct BinaryTree_Node *lchild;
	struct BinaryTree_Node *rchild;
}BinaryTree_Node;
typedef struct BinaryTree
{
	BinaryTree_Node* root;
	//int depth;
}BinaryTree;

BinaryTree* BinaryTree_new();
BinaryTree* BinaryTree_newFromCharArray(char * str);
//BinaryTree_Node* BinaryTree_newNode(BinaryTree_ElemType * e);
BinaryTree_Node* BinaryTree_newNodeCopy(BinaryTree_ElemType * e);
BinaryTree_Node* BinaryTree_getRootNode(BinaryTree * bt);
void BinaryTree_setRootNode(BinaryTree * bt,BinaryTree_Node * node);
BinaryTree_Node* BinaryTree_getLchild(BinaryTree_Node * p);
BinaryTree_Node* BinaryTree_getRchild(BinaryTree_Node * p);
void BinaryTree_setLchild(BinaryTree_Node * p,BinaryTree_Node * cnode);
void BinaryTree_setRchild(BinaryTree_Node * p,BinaryTree_Node * cnode);
static int BinaryTree_depthRootNode(BinaryTree_Node * n);
int BinaryTree_depth(BinaryTree * bt);
static void BinaryTree_preOrderRootNode(BinaryTree_Node * n);
void BinaryTree_preOrder(BinaryTree * bt);
static void BinaryTree_inOrderRootNode(BinaryTree_Node * n);
void BinaryTree_inOrder(BinaryTree * bt);
static void BinaryTree_postOrderRootNode(BinaryTree_Node * n);
void BinaryTree_postOrder(BinaryTree * bt);
void BinaryTree_LevelOrder(BinaryTree * bt);
