//静态分配
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10 //定义最大长度
// #define true 1
// #define false 0

typedef struct{
  int data[MaxSize];
  int length;
}SqList;

//init
void InitList(SqList *L){
  for(int i=0;i<MaxSize;i++)
    L->data[i]=0;
  L->length=0;
}

//插入
bool ListInsert(SqList *L,int i ,int e){ //在i处插入e
    if(i<1||i>L->length+1)
        return false;
    if(L->length>=MaxSize)
        return false;
    for(int j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return true;
}

//main
int main(){
  SqList L;
  InitList(&L);
  ListInsert(&L,1,5);
  for(int i=0;i<MaxSize;i++){
    printf("L.data[%d]=%d\n",i,L.data[i]);
  }
  return 0;
}