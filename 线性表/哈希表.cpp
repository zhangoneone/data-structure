#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int length = 800;
unsigned int m = 0x80000000;
int y0 = 568731;
int savefile(const char *name, char *s)
{
	FILE *fp = NULL;
	fp = fopen(name, "a+");
	fputs(s, fp);
	fclose(fp);
	return 0;
}
int h(int x)
{
	return x;
}
int generate_ramdom(int x[], int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		x[i] = rand() % 1000;
	}
	return 0;
}
int generate_ramdom_another(int x[], int y[], int length)
{
	x[0] = 1000.0*y[0] / (m + 0.1 - 0.1) + 1;
	for (int i = 1; i < length; i++)
	{
		y[i] = (15625 * y[i - 1] + 22221) % m;
		x[i] = 1000.0*y[i] / m;
	}
	return 0;
}
int* create_hashTable(int length)
{
	int *p = (int *)(malloc(sizeof(int)*length));
	for (int i = 0; i < length; p[i] = 0, i++);
	return p;
}
//Ѱ��k�ڹ�ϣ����λ�� k�Ǽ�ֵ 
int search1(int hashtable[], int k)
{
	int i = h(k);//i�������λ�� 
	int j;
	for (j = 0; j < length&&		//��δ���� 
		hashtable[(i + j) % length] != k &&	//ѭ����һ�ֱ� δ�鵽��ֵk ǰ��������ȷ�������������в��Ҽ�ֵk 
		hashtable[(i + j) % length] != 0;	//��������λ�ã����治���ٲ����� 
		j++
		);
	//ִ����forѭ����jҪô(1)�����˱��д�����k��Ҫô(2)���ҵ��˿�λ�� 
	//��ʱ��i��ֵ���������������� 
	i = (i + j) % length;
	if (hashtable[i] == k)//�������1
		return i;
	return -1; //��ʾk���ڱ��� 

}
int insert1(int hashtable[], int k)
{
	int i = h(k);//i�������λ�� 
	int j;
	char s[40];
	//��λ��ֵС�ڵ���0�����Բ���
	//��λ��ֵ����0����Ҫ��̽����λ�� 
	for (j = 0; j < length&&//ȷ��j�ķ�Χ���������� 
		hashtable[(i + j) % length]>0 &&//λ�ñ�ռ 
		hashtable[(i + j) % length] != k;//������������k�Ƿ��Ѿ��������� 
		j++
		);
	//��ʱj������ ��1��Ҫô���Ѿ������k��λ�ã�2��Ҫô��û�б�ռ��λ�� 
	i = (i + j) % length;
	if (hashtable[i] <= 0)//�������2
	{
		//���� 
		hashtable[i] = k;
		sprintf(s, "%d������λ��%d\n", k, i);
		savefile("�����¼.txt", s);
		return 0;
	}
	sprintf(s, "%d�Ѿ�������λ��%d!\n", k, i);
	savefile("��ͻ��¼.txt", s);
	return 1;//�������1,k�Ѿ��ڱ��� 
}
int delete1(int hashtable[], int k)
{
	int i, j;
	i = h(k);
	char s[40];
	for (j = 0; j < length&&
		hashtable[(i + j) % length] != k &&	//û�ҵ�k
		hashtable[(i + j) % length] != 0;		//û������λ��
		j++);
	//��ʱj Ҫô�ҵ�k��Ҫô�ҵ��˿�λ��
	i = (i + j) % length;
	if (hashtable[i] == k)
	{
		hashtable[i] = -1;
		sprintf(s, "�ڹ�ϣ���λ��%dɾ���˼�ֵ%d!\n", i, k);
		savefile("ɾ����¼.txt", s);
		return 1;
	}
	return 0;
}

/*********������ʵ�ֹ�ϣ��***********/

int hashtable_test()
{
	int x[800] = { 0 };
	int y[800];
	char s[50];
	int * hashtable = create_hashTable(length);
	y[0] = 568731;
	generate_ramdom_another(x, y, length);
	for (int i = 0; i < length; i++)
	{
		//	printf("λ��%d�ļ�ֵ��%d",i,x[i]);
		sprintf(s, "λ��:%d��ֵ:%d\n", i, x[i]);
		savefile("ԭʼ�����.txt", s);
	}
	for (int i = 0; i < length; i++)
	{
		insert1(hashtable, x[i]);
	}
	for (int i = 0; i < length; i++)
	{
		sprintf(s, "λ��%d�����˼�ֵ%d\n ", i, hashtable[i]);
		savefile("��ϣ���¼.txt", s);
	}
	for (int i = 0; i < length; i++)
	{
		sprintf(s, "��λ��%d���ҵ���ֵ%d\n ", search1(hashtable, x[i]), x[i]);
		savefile("����¼.txt", s);
	}
	printf("OK!\n");
	while (1)
	{
		int k = 0;
		printf("����Ҫɾ���ļ�ֵ:");
		scanf("%d", &k);
		if (delete1(hashtable, k))
			printf("ɾ���ɹ�\n");
		else
			printf("ɾ��ʧ��\n");
	}
	return 0;
}
