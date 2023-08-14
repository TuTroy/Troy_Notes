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
    int values[] = {1,5,6,8,4,5,5,6};
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

//主要函数
void del_ArrByLim(Array* array,int s,int t){
    if(s>=t || s<0){
        printf("输入的数据有误,s应该小于t s大于0!\n");
        return;
    }
    int k=0;
    for(int i = 0;i<array->length;i++){
        if(array->arr[i]<s || array->arr[i]>t){
            array->arr[k]=array->arr[i];
            k++;
        }
    }
    array->length=k;
}

int main(){
    Array array;
    init_Array(&array);
    printArray(&array);
    int s,t;
    printf("输入删除值的范围：\n");
    scanf("%d %d",&s,&t);
    del_ArrByLim(&array,s,t);
    printArray(&array);
    return 0;
}