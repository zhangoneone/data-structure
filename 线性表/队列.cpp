#include"����.h"
/********��̬���в���**************/

/***********��̬����˽�б���********************/
////�����ʼ״̬Ӧ��Ϊhead=tail=-1
//�п���head==tail
//������tail = MAX-1
static status generic_static_queue_empty(generic_static_queue *q) {
	if (q->queue_head == q->queue_tail)return true;
	else return false;
}
static status generic_static_queue_full(generic_static_queue *q) {
	if (q->queue_tail == MAX_QUEUE_LEN - 1)return true;
	else return false;
}
/***********��̬���й��б���********************/
//���
status generic_static_queue_en(generic_static_queue *q,element x) {
	element *ptr = (element *)q->load;
	if (generic_static_queue_full(q))return -1;
	ptr[q->queue_tail++] = x;
	return 0;
}
//����
status generic_static_queue_de(generic_static_queue *q, element *x) {
	element *ptr = (element *)q->load;
	if (generic_static_queue_empty(q))return -1;
	//�Ⱥ�����ȡ����
	*x = ptr[++q->queue_head];
	return 0;

}

/***********��̬ѭ������˽�б���********************/
//��̬ѭ�����У���ȡ����1���ռ�ķ�ʽ��
//��ʼ״̬��tail��head��Ϊ0����Ϊ������1���ռ䣬�����ȼӣ��ٸ�ֵ����������һ���ռ�
//������tail��head����1λ
//�п���tail����head
static status generic_static_cycle_queue_empty(generic_static_cycle_queue *q) {
	if (q->queue_head == q->queue_tail)return true;
	else return false;
}
static status generic_static_cycle_queue_full(generic_static_cycle_queue *q) {
	if ((q->queue_tail +1)% MAX_QUEUE_LEN == q->queue_head)return true;//tail+1��ȡģ����̽�Ƿ����head������������
	else return false;
}
/***********��̬ѭ�����й��б���********************/
//���
status generic_static_cycle_queue_en(generic_static_cycle_queue *q, element x) {
	element *ptr = (element *)q->load;
	if (generic_static_cycle_queue_full(q))return -1;
	//��Ϊ��ѭ�����У������ȴ���tail��λ��
	q->queue_tail = (q->queue_tail + 1) % MAX_QUEUE_LEN;
	ptr[q->queue_tail] = x;
	return 0;
}
//����
status generic_static_cycle_queue_de(generic_static_cycle_queue *q, element *x) {
	element *ptr = (element *)q->load;
	if (generic_static_cycle_queue_empty(q))return -1;
	//��Ϊ��ѭ�����У������ȴ���head��λ��
	q->queue_head = (q->queue_head + 1) % MAX_QUEUE_LEN;
	//ȡ����
	*x = ptr[q->queue_head];
	return 0;
}

/***********��̬˫�����˽�б���********************/
//��ʼ״̬Ӧ����m = (MAX_QUEUE_LEN -1)/2
//left = m+1,right = m
/*
static status generic_static_double_queue_empty(generic_static_double_queue *q) {
	if (q->queue_head == q->queue_tail)return true;
	else return false;
}
static status generic_static_double_queue_full(generic_static_double_queue *q) {
	if ((q->queue_tail + 1) % MAX_QUEUE_LEN == q->queue_head)return true;//tail+1��ȡģ����̽�Ƿ����head������������
	else return false;
}
*/
/***********��̬˫����й��б���********************/