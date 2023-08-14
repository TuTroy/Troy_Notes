#include <stdio.h>
#include <stdbool.h>
#define Maxsize 100

//定义结构体
typedef struct SqList{
  int arr[Maxsize];
  int length;
}Array;

//初始化数组--参数为指针，也可以理解为数组，数组相当于有自己的地址
//数组的赋值： 一旦数组被定义，就不能再使用花括号直接给数组赋值。数组元素只能逐个进行赋值，或者使用循环等方法进行批量赋值。
void init_Array(Array* array){
    array->length = 8;//c语言中不能用花括号赋值
    int values[] = { 1,2,3,3,4,5,5,6};
    for(int i =0;i<array->length;i++){
        array->arr[i]=values[i];
    }
}

//打印表中元素
void printArray(Array* array){
    printf("数组元素为：\n");
    for(int i =0;i<array->length;i++){
        printf("%d ",array->arr[i]);
    }
    printf("\n");
}

void removeDuplicates(Array* array){
  if(array == NULL || array->length == 0){
    return;
  }
  int currentIndex = 0; //初始指针指向第一个元素
  for(int i=1;i<array->length;i++){
    if(array->arr[i]!=array->arr[currentIndex]){
      currentIndex++;
      array->arr[currentIndex]=array->arr[i];
    }
  }
  array->length=currentIndex+1;
}


int main(){
    Array array;
    init_Array(&array);
    removeDuplicates(&array);
    printArray(&array);
}