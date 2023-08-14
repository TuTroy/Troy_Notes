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
    array->length = 11;//c语言中不能用花括号赋值
    int values[] = {1,2,3,4,5,6,7,8,9,10,11};
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

//整个数组元素翻转函数
//用指针可以直接改变内存中的值
void reverseAtoB(Array* array,int i ,int j){
    int* first = &(array->arr[i]);
    int* end = &(array->arr[j]);
    while(first < end){
        int temp = *first;
        *first = *end;
        *end = temp;
        first++;
        end++;
    }
}
void reverseAtoB1(Array array,int i ,int j){
    while(i<j){
        int temp = array.arr[i];
        array.arr[i]=array.arr[j];
        array.arr[j]=temp;
        i++;
        j++;
    }
}


//多个数组翻转
void arrayResver(Array* array,int n){
    // reverseAtoB(array,0,array->length -1);
    // reverseAtoB(array,0,n-1);
    // reverseAtoB(array,n,array->length -1);
}
void arrayResver1(Array array,int m,int n){
    reverseAtoB1(array,0,m+n-1);
    reverseAtoB1(array,0,n-1);
    reverseAtoB1(array,n,m+n-1);
}

int main(){
  Array array;
  init_Array(&array);
  //printArray(&array);
  arrayResver1(array,5,6);
  printArray(&array);
}