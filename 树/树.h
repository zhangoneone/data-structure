#pragma once
#include"common.h"


#define ShowFun(fmt,...) printf(fmt,__VA_ARGS__);
#define THR_TREE	1
#define AVL_TREE	1
#define HUFFMAN_TREE	1

typedef struct TreeNode {
	bool ltag;
	struct TreeNode *lchild;
	element data;
	struct TreeNode *rchild;
	bool rtag;
	int node_cost;//��������Ҫʹ�õĽ�����ֵ
	int balance_fact;//avl��ƽ������
}TreeNode, *Tree;//����������������������һ�������

typedef int(*visit_t)(TreeNode* node, TreeNode* OutNode, void* args);
