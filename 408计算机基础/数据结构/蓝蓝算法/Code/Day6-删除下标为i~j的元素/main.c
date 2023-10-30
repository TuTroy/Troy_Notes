#include <stdio.h>
#define Maxsize 100

//定义结构体
typedef struct SqList{
  int arr[Maxsize];
  int length;
}Array;

//初始化数组--参数为指针，也可以理解为数组，数组相当于有自己的地址
void init_Array(Array* array){
  scanf("%d",&(array->length));//输入数组长度
  for(int i =0;i<array->length;i++){
    scanf("%d",&(array->arr[i]));
  }
}

//删除指定位置元素
void del_arr(Array* array,int i,int j){
  int p =j+1;
  int q =i;
  while(p<array->length){
    array->arr[q]=array->arr[p];
    q++;
    p++;
  }
  array->length = array->length-(j-i)-1;
}

//打印表中元素
void printArray(Array* array){
  for(int i =0;i<array->length;i++){
    printf("%d",array->arr[i]);
  }
  printf("\n");
}

int main(){
  int test[]={1,2,3,4,5};
  int len = sizeof(test)/sizeof(test[0]);
  //init SqList other way
  //Array array = {{1,2,3,4,5},5};
  Array array;
  array.length = len;
  for(int i =0;i<len;i++){
    array.arr[i]=test[i];
  }
  //初始化顺序表
  //init_Array(&array);
  del_arr(&array,1,1);
  printArray(&array);
  return 0;
}