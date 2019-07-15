#pragma once
#include"../公共文件/common.h"
#define MAX_STACK_LEN	100
typedef element generic_static_stack_load[MAX_STACK_LEN];//静态栈
typedef struct {
	generic_static_stack_load load;
	int stack_top;
}generic_static_stack;
