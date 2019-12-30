#include"树.h"
#include"stdlib.h"

//创建一个只有根节点的空树
Tree Tree_create() {
	return (Tree)malloc(sizeof TreeNode); 
}

//计算左右子树的高度，并返回树的高度
int Tree_LR_Height(Tree T,int *L_Height,int *R_Height) {
	int L = 0, R = 0;
	if (T->lchild == NULL && T->rchild == NULL)return 0;
	if (T->lchild != NULL)L = 1 + Tree_LR_Height(T->lchild, L_Height, R_Height);
	if (T->rchild != NULL)R = 1 + Tree_LR_Height(T->rchild,L_Height, R_Height);
	*L_Height = L;
	*R_Height = R;
	return  *L_Height > *R_Height ? *L_Height : *R_Height;
}
//返回树的高度
int Tree_LR_Height2(Tree T) {
	int L = 0, R = 0;
	if (T->lchild == NULL && T->rchild == NULL)return 0;
	if (T->lchild != NULL)L = 1+Tree_LR_Height2(T->lchild);
	if (T->rchild != NULL)R = 1+Tree_LR_Height2(T->rchild);
	return L > R ? L : R;
}
//计算T的左右子树的高度差,左减右的差值
int Tree_LR_Height_Deviation(Tree T) {
	int L = 0, R = 0;
	Tree_LR_Height(T, &L, &R);
	return L - R;
}
//计算二叉树的高度
int Tree_Height(Tree T) {
	int L_Height = 0;
	int R_Height = 0;
	return Tree_LR_Height(T, &L_Height, &R_Height);
}

//树的遍历,visit函数，中序遍历
int Tree_Traversal(Tree T,visit_t visit, Tree visit_prama1,void*visit_prama2){
	if(T) {
		Tree_Traversal(T->lchild, visit, visit_prama1, visit_prama2);
		visit(T,visit_prama1, visit_prama2);
		Tree_Traversal(T->rchild, visit, visit_prama1, visit_prama2);
	}
	return 0;
}

//访问方式:遍历时找到主键e对应的结点，则保存该结点的引用
//找到则savenode结点有了合适的值
static int VisitMode_SameReturn(TreeNode* node, TreeNode* saveNode,void* e) {
	if (node->data == *(element*)e) {
		saveNode = node; return 0;
	}
}

//访问方式:输出主键值,ShowFun是打印函数
static int VisitMode_ShowValue(TreeNode* node, TreeNode* arg1, void*args) {
	static int i = 0;
	ShowFun("中序遍历第%d个结点值:%d\n", i,node->data);
	return 0;
}


//通过主键e找到node并返回node本身的指针,并指定访问方式
//这种方式强制遍历了整个树，不是最好的办法
TreeNode* Tree_Find_Node_Fun(Tree T,element e,visit_t visit) {
	TreeNode* node=NULL;
	Tree_Traversal(T, visit, node, (void*)&e);
	return node;
}
//通过主键e找到node并返回node本身的指针,savenode保存找到的node.传入的savenode应该是NULL
TreeNode* Tree_Find_Node(Tree T, TreeNode*savenode, element e) {
	if (T) {
		return savenode?savenode:Tree_Find_Node(T->lchild, savenode, e);
		if (T->data == e)savenode = T;
		return savenode?savenode:Tree_Find_Node(T->rchild, savenode,e);
	}
	return savenode;
}

//node加入T的叶子上,平衡二叉树
int Tree_add(Tree T, TreeNode *node) {
	if (T) {//未找到插入点前
		int deviation = 0;
		deviation = Tree_LR_Height_Deviation(T);
		if (deviation <= 0)Tree_add(T->lchild, node);
		else Tree_add(T->rchild, node);
	}
	else
		T = node;
	return 0;
}

//remove后的结点以指针返回。并且从树上摘除。返回NULL则不存在该结点
TreeNode* Tree_remove(Tree T,element e) {
	TreeNode*savenode = NULL;
	Tree_Find_Node(T, savenode, e);
	if (savenode) {//找到则删除

	}
	return savenode;
}
//delete后的结点被free了内存。并且从树上摘除
//返回0代表找到并且删除并且free，否则代表没找到或者没删除或者没有free
int Tree_delete(Tree T, element e) {
	TreeNode*savenode = NULL;
	Tree_Find_Node(T, savenode, e);
	if (savenode) {//找到则删除

		return 0;
	}
	return -1;
}

//以元素列表生成一颗avl树，返回树根结点
Tree Tree_init(element e_list[],int len) {
	int i = 0;
	TreeNode *node = NULL;
	Tree T = Tree_create();
	if (!T)return T;
	for (i = 0; i < len; i++) {
		node = (TreeNode*)malloc(sizeof(TreeNode));
		Tree_add(T,node);
	}
	Tree_Traversal(T, VisitMode_ShowValue, 0, 0);
	return T;
}

//销毁avl树，并free内存
int Tree_destroy(Tree T) {
	if (T) {
		Tree_destroy(T->lchild);
		Tree_destroy(T->rchild);
		if (T->lchild == NULL && T->rchild == NULL)free(T);
	}
	return 0;
}