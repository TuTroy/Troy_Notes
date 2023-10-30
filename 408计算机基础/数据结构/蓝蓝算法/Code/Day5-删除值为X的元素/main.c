//设计高效算法,将L所有元素逆置
//空间复杂度为O(1)
//知识点：顺序表的遍历+双指针_下标

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
}SqList;

//init - 最大长度的值初始化为0，长度为0
void InitList(SqList *L){ 
    //如果不用指针的话只是对函数的一个副本进行修改，而不是对原来的L进行修改
    //用*L相当于传递了一个指向L的结构体的指针，函数对L的修改会影响到实参的修改
    L->length=0;
    printf("初始化顺序表\n");
    for(int i=0;i<MaxSize;i++){
        L->data[i]=0;
        //printf("%d\n",L->data[i]);
    }
}

//输出线性表
void PrintList(SqList L){
    printf("顺序表中的元素为:\n");
    for(int i =0;i< L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n\n");
    printf("顺序表最大长度：%d\n",MaxSize);
    printf("顺序表当前长度：%d\n",L.length);
    printf("\n");
}

//线性表当前长度
int ListLength(SqList L){
    return L.length;
}

//插入
//位序是从1开始，数组中元素的下标从0开始
bool ListInsert(SqList *L,int i ,int e){ //在i处插入e
    if(i<1||i>L->length+1) //判断i的位置是否有效 i从1开始到表长
        return false;
    if(L->length>=MaxSize) //表满不能插入了
        return false;
    for(int j=L->length;j>=i;j--) //把第i个元素以及之后的元素往后移
        L->data[j]=L->data[j-1];
    L->data[i-1]=e; // 在位置i处加入e
    L->length++; //表长++
    return true;
}

//删除值为x的数据元素,时间复杂度O(n)
//step1查找不为X的值，重新装入数组
//step2设置k为新下标，每次不相等就装入并且k++
void ListDeleteX(SqList *L,int x){
    int k=0;
    for(int i=0;i<L->length;i++){
        if(L->data[i]!=x){
            L->data[k++]=L->data[i];
        }
    }
    L->length=k;
}


int main(){
    SqList L;
    InitList(&L); //&为取地址符，将地址作为参数传给函数
    //对于不涉及指针的函数参数，例如整数、字符等基本数据类型，直接通过值传递即可。
    //在这种情况下，不需要使用&操作符来传递变量的地址，
    //因为这些基本数据类型在函数调用时会被复制一份，函数对其进行的修改不会影响原始变量。
    int loc;
    printf("输入插入位置：\n");
    while(scanf("%d",&loc)== 1){        
        int num;
        printf("输入插入数字：\n");
        scanf("%d",&num);
        printf("输入插入位置：\n");
        ListInsert(&L,loc,num);
    }
    PrintList(L);
    ListDeleteX(&L,1);
    PrintList(L);
    int l=ListLength(L);
    printf("%d\n",l);
}