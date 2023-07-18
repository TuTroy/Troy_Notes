//动态分配
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10 //表长初始定义

typedef struct{
  int *data;//动态分配数组指针
  int MaxSize,length;
}SeqList;

//init
void InitList(SeqList *L){
  L->data=(int *)malloc(InitSize*sizeof(int));
  L->length=0;
  L->MaxSize=InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList *L,int len){
  int *p=L->data;// 保存旧的数据指针
  L->data=(int *)malloc((L->MaxSize+len)*sizeof(int));// 重新分配更大的内存空间
  for(int i=0;i<L->length;i++){// 将旧数据复制到新内存空间
    L->data[i]=p[i];
  }
  L->MaxSize=L->MaxSize+len; //更新最大长度
  free(p); //释放旧的内存空间
}


//main
int main(){
  SeqList L;
  InitList(&L);
  IncreaseSize(&L,5);
  for(int i=0;i< L.MaxSize;i++){ //此时L是一个结构体而不是指针，因此需要用L.MaxSize表示不能用L->MaxSize
    printf("L.data[%d]=%d\n",i,L.data[i]); 
  }
  return 0;
}