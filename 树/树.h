#pragma once
#include"common.h"
typedef struct TreeNode {
	bool ltag;
	struct TreeNode *lchild;
	element data;
	struct TreeNode *rchild;
	bool rtag;
	int node_cost;//��������Ҫʹ�õĽ�����ֵ
}TreeNode, *Tree;//����������������������һ�������

typedef int(*visit_t)(TreeNode* node, TreeNode* OutNode, void* args);

#define ShowFun(fmt,...) printf(fmt,__VA_ARGS__);