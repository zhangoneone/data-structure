#pragma once
#include"../�����ļ�/common.h"
#define MAX_QUEUE_LEN	100
typedef element generic_static_queue_load[MAX_QUEUE_LEN];//��̬����
typedef struct {
	generic_static_queue_load load;
	int queue_head;//����headָ���Ŷ���ͷ����ǰһ����㡣
	int queue_tail;//����tailָ���Ŷ���β��㡣
}generic_static_queue;

typedef struct {
	generic_static_queue_load load;
	int queue_head;//����headָ���Ŷ���ͷ����ǰһ����㡣
	int queue_tail;//����tailָ���Ŷ���β��㡣
}generic_static_cycle_queue;//���鶨���ѭ������

typedef struct {
	generic_static_queue_load load;
	int queue_left;//����headָ���Ŷ���ͷ����ǰһ����㡣
	int queue_right;//����tailָ���Ŷ���β��㡣
}generic_static_double_queue;//���鶨���˫�����

