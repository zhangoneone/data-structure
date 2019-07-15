#pragma once
#include"../公共文件/common.h"
#define MAX_QUEUE_LEN	100
typedef element generic_static_queue_load[MAX_QUEUE_LEN];//静态队列
typedef struct {
	generic_static_queue_load load;
	int queue_head;//这里head指向存放队列头结点的前一个结点。
	int queue_tail;//这里tail指向存放队列尾结点。
}generic_static_queue;

typedef struct {
	generic_static_queue_load load;
	int queue_head;//这里head指向存放队列头结点的前一个结点。
	int queue_tail;//这里tail指向存放队列尾结点。
}generic_static_cycle_queue;//数组定义的循环队列

typedef struct {
	generic_static_queue_load load;
	int queue_left;//这里head指向存放队列头结点的前一个结点。
	int queue_right;//这里tail指向存放队列尾结点。
}generic_static_double_queue;//数组定义的双向队列

