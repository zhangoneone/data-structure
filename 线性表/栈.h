#pragma once
#include"common.h"
#define MAX_STACK_LEN	100
typedef element generic_static_stack_load[MAX_STACK_LEN];//¾²Ì¬Õ»
typedef struct {
	generic_static_stack_load load;
	int stack_top;
}generic_static_stack;
