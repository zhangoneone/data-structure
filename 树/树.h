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
	int node_cost;//哈夫曼树要使用的结点代价值
	int balance_fact;//avl树平衡因子
}TreeNode, *Tree;//线索二叉树的声明，兼容一般二叉树

typedef int(*visit_t)(TreeNode* node, TreeNode* OutNode, void* args);
