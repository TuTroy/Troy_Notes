#include <stdio.h>
#define Maxsize 100

//定义结构体
typedef struct SqList{
  int arr[Maxsize];
  int length;
}Array;

//初始化数组--参数为指针，也可以理解为数组，数组相当于有自己的地址
void init_Array(Array* array){
    printf("输入数组长度:\n");
    scanf("%d",&(array->length));//输入数组长度
    for(int i =0;i<array->length;i++){
        printf("第%d个值为\n",(i+1));
        scanf("%d",&(array->arr[i]));
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