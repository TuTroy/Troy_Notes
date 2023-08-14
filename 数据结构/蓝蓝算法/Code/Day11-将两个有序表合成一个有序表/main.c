#include <stdio.h>
#include <stdlib.h>
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
    int values[] = {1,2,3,4,5,6,7,8};
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

Array mergerSortSequence(Array* array1,Array* array2){
    Array array3;
    //= (Array*)malloc(sizeof(Array)); // 分配内存空间
    int k1=0,k2=0,k3=0;
    while(k1<array1->length && k2 < array2->length){
        if(array1->arr[k1]<=array2->arr[k2]){
            array3.arr[k3++]=array1->arr[k1++];//k++是先赋值再++、++k先++在赋值
        }
        else{
            array3.arr[k3++]=array2->arr[k2++];
        }
    }
    while(k1 < array1->length){
        array3.arr[k3++]=array1->arr[k1++];
    }
    while(k2 < array2->length){
        array3.arr[k3++]=array2->arr[k2++];
    }
    array3.length = k3;//为什么不是k3+1
    return array3;
}

int main(){
    Array array1,array2;
    init_Array(&array1);
    printArray(&array1);
    init_Array(&array2);
    printArray(&array2);
    Array array3 = mergerSortSequence(&array1,&array2);
    printArray(&array3); //array3通过malloc函数动态分配得到的内存，mergerSortSequence()内部返回的是指向动态分配内存的指针，此时array3作为指针变量
    //free(&array3);
    return 0;
}