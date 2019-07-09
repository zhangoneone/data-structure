#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Max 1000000
/*********保存到文件***************/
/*

***********************************/
int ToFile(char *name,char buff[])
{
    FILE *fp;
    fp=fopen(name,"a+");//追加模式
    fwrite(buff,sizeof(char),sizeof(char)*Max,fp);
 //   fwrite((char *)0x0d,sizeof(char),1,fp);//写入换行
    fflush(fp);
    fclose(fp);
}
/*********产生随机数***************/
/*

***********************************/
void yield_random_number(int *randomArray, int num)
{
    time_t t;
    int i=0;
    srand((unsigned) time(&t));
    for(;i<num;i++)
    {
       // randomArray[i]=(rand()&(~(1<<31)));
        randomArray[i]=rand();
    }
}
/*********归并两个有序数组***************/
/*
L1:左区间的开始下标
R1:左区间的结束下标
L2:右区间的开始下标
R2:右区间的结束下标
***********************************/
void merge(int A[],int L1,int R1,int L2,int R2)
{
    int i=L1,j=L2,index=0,tmparray[Max];
    while(i<=R1&&j<=R2)//注意此处有“=”，比如传入0 0 1 1，即每组只有1个数也要排序
    {
        if(A[i]<=A[j]){
            tmparray[index++]=A[i++];
        }
        else{
            tmparray[index++]=A[j++];
        }
    }
    while(i<=R1){tmparray[index++]=A[i++];}
    while(j<=R2){tmparray[index++]=A[j++];}
    //写回
    for(i=0;i<index;i++)
    {
        A[L1+i]=tmparray[i];
    }
}
/*********归并排序的递归实现***************/
/*
left:起点
right:终点
***********************************/
void mergeSort(int A[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);//递归左子区间
        mergeSort(A,mid+1,right);//递归右子区间
        merge(A,left,mid,mid+1,right);//归并
    }
}
int main(int __argc,char **__argv)
{
    int A[100]={0};
    yield_random_number(A,Max);
   // for(int i=0;i<Max;i++){
    //    printf("%d\n",A[i]);
   // }
  //  ToFile("initial digital.txt",A);
    mergeSort(A,0,Max-1);//这里传入的是下标
   // printf("归并后\n");
   // for(int i=0;i<Max;i++){
   //     printf("%d\n",A[i]);
   // }
   // ToFile("merged digital.txt",A);
 //   getchar();
    return 0;
}