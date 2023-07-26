//从顺序表中删除最小元素，
//并且返回被删除元素的值，
//空出的位置由最后一个元素填补
//顺序表+最小值+数组遍历

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 50
typedef struct 
{
    int *data;
    int MaxSize,length;
}Seqlist;

//初始化线性表
void InitList(Seqlist *L){
    L->length =0;
}

//创造一个顺序表
void CreateList(Seqlist *L,int a[],int n){
    L->data = (int*)malloc(sizeof(int)*InitSize);
    for(int i=0;i<n;i++){
        L->data[i]=a[i];
        L->length++;
    }
}

//输出线性表
void PrintList(Seqlist *L){
    printf("顺序表中的元素为:\n");
    for(int i =0;i< L->length;i++){
        printf("%4d",L->data[i]);
    }
    printf("\n\n");
}

//线性表当前长度
void ListLength(Seqlist *L){
    return L->length;
}


int removeMinValue(int* sequence,int* length){
    if(*length ==0){
        fprintf(stderr,"顺序表为空！\n");
        return -1;
    }

    int minInd =0;
    int minVal = sequence[0];

    for(int i=1;i<length;i++){
        if(sequence[i]<minVal){
            minVal = sequence[i];
            minInd = i;
        }
    }

    int deleteVal = sequence[minInd];
    sequence[minInd]=sequence[*length-1];
    *length-=1;
    return deleteVal;
}

int main(){
    Seqlist L,*SP;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    CreateList(SP,a[10],4);
    PrintList(SP);
}