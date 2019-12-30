#pragma once
#include"common.h"
typedef struct TreeNode {
	bool ltag;
	struct TreeNode *lchild;
	element data;
	struct TreeNode *rchild;
	bool rtag;
	int node_cost;//哈夫曼树要使用的结点代价值
}TreeNode, *Tree;//线索二叉树的声明，兼容一般二叉树

typedef int(*visit_t)(TreeNode* node, TreeNode* OutNode, void* args);

#define ShowFun(fmt,...) printf(fmt,__VA_ARGS__);