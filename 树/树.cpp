#include"��.h"
#include"stdlib.h"
/*********************�궨����*************************/
/*********************�궨����end*************************/
/*********************���Ͷ�����*************************/
/*********************���Ͷ�����end*************************/

/*********************˽�к�����*************************/
//���ʷ�ʽ:����ʱ�ҵ�����e��Ӧ�Ľ�㣬�򱣴�ý�������
//�ҵ���savenode������˺��ʵ�ֵ
static int VisitMode_SameReturn(TreeNode* node, TreeNode* saveNode, void* e) {
	if (node->data == *(element*)e) {
		saveNode = node; return 0;
	}
}

//���ʷ�ʽ:�������ֵ,ShowFun�Ǵ�ӡ����
static int VisitMode_ShowValue(TreeNode* node, TreeNode* arg1, void*args) {
	static int i = 0;
	ShowFun("����������ֵ:%d\n", node->data);
	return 0;
}

/*********************˽�к�����end*************************/

/*********************���������в���������*************************/
//����һ��ֻ�и��ڵ�Ŀ���
Tree Tree_create() {
	Tree T;
	T = (Tree)malloc(sizeof TreeNode);
	T->lchild = T->rchild = NULL;
	T->data = -1;
	return T;
}

//�������������ĸ߶ȣ����������ĸ߶�
int Tree_LR_Height(Tree T, int *L_Height, int *R_Height) {
	int L = 0, R = 0;
	if (T == NULL)return 0;
	if (T->lchild == NULL && T->rchild == NULL)return 0;
	if (T->lchild != NULL)L = 1 + Tree_LR_Height(T->lchild, L_Height, R_Height);
	if (T->rchild != NULL)R = 1 + Tree_LR_Height(T->rchild, L_Height, R_Height);
	*L_Height = L;
	*R_Height = R;
	T->lchild->balance_fact = L;
	T->rchild->balance_fact = R;
	return  *L_Height > *R_Height ? *L_Height : *R_Height;
}
//�������ĸ߶�
int Tree_LR_Height2(Tree T) {
	int L = 0, R = 0;
	if (T->lchild == NULL && T->rchild == NULL)return 0;
	if (T->lchild != NULL)L = 1 + Tree_LR_Height2(T->lchild);
	if (T->rchild != NULL)R = 1 + Tree_LR_Height2(T->rchild);
	return L > R ? L : R;
}
//����T�����������ĸ߶Ȳ�,����ҵĲ�ֵ
int Tree_LR_Height_Deviation(Tree T) {
	int L = 0, R = 0;
	Tree_LR_Height(T, &L, &R);
	return L - R;
}
//����������ĸ߶�
int Tree_Height(Tree T) {
	int L_Height = 0;
	int R_Height = 0;
	return Tree_LR_Height(T, &L_Height, &R_Height);
}

//���ı���,visit�������������
int Tree_Traversal(Tree T, visit_t visit, Tree visit_prama1, void*visit_prama2) {
	if (T) {
		Tree_Traversal(T->lchild, visit, visit_prama1, visit_prama2);
		visit(T, visit_prama1, visit_prama2);
		Tree_Traversal(T->rchild, visit, visit_prama1, visit_prama2);
	}
	return 0;
}
//ͨ������e�ҵ�node������node�����ָ��,��ָ�����ʷ�ʽ
//���ַ�ʽǿ�Ʊ�������������������õİ취
TreeNode* Tree_Find_Node_Fun(Tree T, element e, visit_t visit) {
	TreeNode* node = NULL;
	Tree_Traversal(T, visit, node, (void*)&e);
	return node;
}
//ͨ������e�ҵ�node������node�����ָ��,savenode�����ҵ���node.�����savenodeӦ����NULL
TreeNode* Tree_Find_Node(Tree T, TreeNode*savenode, element e) {
	if (T) {
		return savenode ? savenode : Tree_Find_Node(T->lchild, savenode, e);
		if (T->data == e)savenode = T;
		return savenode ? savenode : Tree_Find_Node(T->rchild, savenode, e);
	}
	return savenode;
}
//node����T��Ҷ����,ƽ���������������������
int Tree_add(Tree *T, TreeNode *node) {
	if (*T) {//δ�ҵ������ǰ
		int deviation = 0;
		deviation = Tree_LR_Height_Deviation(*T);
		if (deviation <= 0)Tree_add(&((*T)->lchild), node);
		else Tree_add(&((*T)->rchild), node);
	}
	else
		*T = node;
	return 0;
}

//remove��Ľ����ָ�뷵�ء����Ҵ�����ժ��������NULL�򲻴��ڸý��
TreeNode* Tree_remove(Tree *T, element e) {
	TreeNode*savenode = NULL;
	Tree_Find_Node(*T, savenode, e);
	if (savenode) {//�ҵ���ɾ��

	}
	return savenode;
}
//delete��Ľ�㱻free���ڴ档���Ҵ�����ժ��
//����0�����ҵ�����ɾ������free���������û�ҵ�����ûɾ������û��free
int Tree_delete(Tree *T, element e) {
	TreeNode*savenode = NULL;
	Tree_Find_Node(*T, savenode, e);
	if (savenode) {//�ҵ���ɾ��

		return 0;
	}
	return -1;
}
//��Ԫ���б�����һ����ͨ���������������
Tree Tree_init(element e_list[], int len) {
	int i = 0;
	TreeNode *node = NULL;
	Tree T = Tree_create();
	if (!T)return T;
	for (i = 0; i < len; i++) {
		node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = e_list[i];
		node->lchild = node->rchild = NULL;
		Tree_add(&T, node);
	}
	Tree_Traversal(T, VisitMode_ShowValue, 0, 0);
	return T;
}

//����������free�ڴ�
int Tree_destroy(Tree T) {
	if (T) {
		Tree_destroy(T->lchild);
		Tree_destroy(T->rchild);
		if (T->lchild == NULL && T->rchild == NULL) { free(T); T = NULL; };
	}
	return 0;
}

/*********************���������в���������end*************************/


/*********************������������*************************/
#if (THR_TREE==1)
//��pre��cur��������������tagΪ0���������������tagΪ1����������ӽ��
//������û�����ӣ���ô��ָ���Լ��ĸ��ڵ㣬������û���Һ��ӣ���ô��ָ���Լ������������һ�����
int do_Thr(TreeNode *pre, TreeNode *cur) {
	if (pre) {
		if (pre->rchild == NULL) {
			pre->rtag = 0;
			pre->rchild = cur;
			ShowFun("%d�ĺ����%d\n", pre->data, cur->data);
		}
		else pre->rtag = 1;
	}
	if (cur) {
		if (cur->lchild == NULL) {
			cur->ltag = 0;
			cur->lchild = pre;
			if (pre)ShowFun("%d��ǰ����%d\n", cur->data, pre->data);
		}
		else cur->ltag = 1;
	}
	return 0;
}

//��������T,�������������
int Tree_Thr_Traversal(Tree T, int node_num) {
	TreeNode*pre = NULL, *cur = T;
	TreeNode** stk = (TreeNode **)malloc(sizeof(TreeNode*)*node_num);
	int top = 0;
	while (top > 0 || cur) {
		if (cur) {//������������ѹջ
			stk[top++] = cur;
			cur = cur->lchild;
		}
		else {//�������ͷ�ˣ���ջ����
			cur = stk[--top];
			do_Thr(pre, cur);
			pre = cur;
			cur = cur->rchild;
		}
	}
	return 0;
}

#endif
/*********************������������end*************************/

/*********************avl����*************************/
#if (AVL_TREE==1)
//avl����һ��ƽ���������������ÿ�β��붼������ģ�ÿ�β����ɾ����Ҫ��ת����
//�����Ҫ��д���룬ɾ��������
//ʹ�����򣬼�������С�ڸ�����С��������

//��������
int Avl_Tree_LL(Tree *Ancestor,Tree *T) {

	return 0;
}

//�������δ�
int Avl_Tree_RR(Tree *Ancestor,Tree *T) {

	return 0;
}
//����һ�Σ�����һ��
int Avl_Tree_LR(Tree *Ancestor,Tree *T) {

	return 0;
}
//����һ�Σ�����һ��
int Avl_Tree_RL(Tree *Ancestor,Tree *T) {

	return 0;
}

int Avl_Tree_add(Tree *T, TreeNode *node) {
	if (*T) {
		if ((*T)->data > node->data)Avl_Tree_add(&(*T)->lchild, node);
		else if((*T)->data < node->data)Avl_Tree_add(&(*T)->rchild, node);
		else return -1;
		(*T)->balance_fact = Tree_LR_Height_Deviation(*T);//����ƽ������
		if ((*T)->balance_fact >= 2) {//����б
			if ((*T)->lchild->lchild->lchild || (*T)->lchild->lchild->rchild)
				Avl_Tree_LL(T);
			if ((*T)->lchild->rchild->lchild || (*T)->lchild->rchild->rchild)
				Avl_Tree_LR(T);
		}
		else if ((*T)->balance_fact <= -2) {//����б
			if ((*T)->rchild->rchild->lchild || (*T)->rchild->rchild->rchild)
				Avl_Tree_RR(T);
			if ((*T)->rchild->lchild->lchild || (*T)->rchild->lchild->rchild)
				Avl_Tree_RL(T);
		}
	}
	else {
		*T = node;
		(*T)->balance_fact = 0;
	}
	return 0;
}


#endif
/*********************avl����end*************************/

/*********************����������*************************/
#if (HUFFMAN_TREE==1)

#endif
/*********************����������end*************************/





/**********************������������************************************/

int main() {
	element e_list[10] = { 5,3,6,1,7,8,4,9,2,0 };
	Tree T = Tree_init(e_list, 10);
	T->data = -1;
	Tree_Thr_Traversal(T, 11);
	getchar();
}