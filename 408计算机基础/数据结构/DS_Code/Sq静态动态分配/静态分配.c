//静态分配
#include <stdio.h>
#define MaxSize 10 //定义最大长度

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

//main
int main(){
  SqList L;
  InitList(&L);
  for(int i=0;i<MaxSize;i++){
    printf("L.data[%d]=%d\n",i,L.data[i]);
  }
  return 0;
}
