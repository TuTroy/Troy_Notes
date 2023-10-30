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
  for(int i =0;i<array->length;i++){
    printf("%d ",array->arr[i]);
  }
  printf("\n");
}

void partition(Array *sequence,int length){
  if(sequence->length == 0){
    return;//错值返回
  }
  int pivot = sequence->arr[0];//表头元素作为枢轴
  int left =1; //左指针指向第二个元素
  int right = length -1;//右指针指向最后一个元素
  
  while(left <= right){
    //左指针大于pivot的元素
    while(sequence->arr[left]<=pivot){
      left++;
    }
    //右指针小于pivot的元素
    while(sequence->arr[right]>pivot){
      right--;
    }
    if(left < right){
      //交换元素
      int tmp = sequence->arr[left];
      sequence->arr[left]=sequence->arr[right];
      sequence->arr[right]=tmp;
      left++;
      right--;
    }
  }
  //把表头元素放到中间去
  int tmp = sequence->arr[0];
  sequence->arr[0]=sequence->arr[right];
  sequence->arr[right]=tmp;
}


int main(){
    //int test[9]={5,1,9,4,3,2,6,8};
    Array test;
    init_Array(&test);
    printArray(&test);
    partition(&test,9);
    printArray(&test);

}