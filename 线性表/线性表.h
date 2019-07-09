#pragma once
#include"common.h"
#define MAX_LIST_LEN		100
typedef element generic_static_list[MAX_LIST_LEN];//��̬��

typedef struct generic_dynamic_single_list {
	element value;
	struct generic_dynamic_single_list *next;
}generic_dynamic_single_list;//������

typedef struct generic_dynamic_double_list {
	element value;
	struct generic_dynamic_double_list *next;
}generic_dynamic_double_list;//˫������

typedef struct generic_dynamic_double_cycle_list {
	element value;
	struct generic_dynamic_double_cycle_list *next;
}generic_dynamic_double_cycle_list;//˫��ѭ������
