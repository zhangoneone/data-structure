#include"ջ.h"
/********��̬ջ����**************/
/***********��̬ջ˽�б���********************/
//ջ��ʱtopָ��Ϊ0����ʱtopָ����max+1
static status generic_static_stack_empty(generic_static_stack *s) {
	if (s->stack_top == 0)return true;
	else return false;
}
static status generic_static_stack_full(generic_static_stack *s) {
	if (s->stack_top == MAX_STACK_LEN + 1)return true;
	else return false;
}
/***********��̬ջȫ�ֱ���********************/
status generic_static_stack_push(generic_static_stack *s,element x) {
	//����д������Ҫ�ȷ����ݣ���top++
	element *ptr = (element *)s->load;
	if (generic_static_stack_full(s))return -1;
	s->load[s->stack_top++] = x;
	return 0;
}

status generic_static_stack_pop(generic_static_stack *s, element *x) {
	//����д������Ҫ��top--���ٳ�����
	element *ptr = (element *)s->load;
	if (generic_static_stack_empty(s))return -1;
	*x = s->load[--s->stack_top];
	return 0;
}