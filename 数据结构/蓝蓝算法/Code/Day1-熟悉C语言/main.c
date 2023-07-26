#include <stdio.h>
#include <stdlib.h>
//考试无特殊情况 能用数组用数组

//定义结构体
struct Student{
    char name[20];
    int num;
    float score;
};
//使用typedef
typedef struct student{

}stu,*student1;
// stu 时声明变量的别名 stu z; 等价struct student z; 
// student1是声明指针的别名 student y; 等价 struct student *y;




int main(){
    struct Student stu1;
    stu1.num = 10;
    //printf("%d\n",stu1.num);

    // 4.指针
    int a = 10;
    int* p = &a; //int*为定义一个指针 p 指向a的地址 
    *p += 5;
    //printf("*p=%d\n",*p);
    //printf("a= %d\n",a);
    //题目：for循环实现1+2+3+4+...+10
    int g[10];
    int sum=0;
    for(int i=1;i<=10;i++){
        g[i-1]=i;
        sum += g[i-1];
    }
    printf("sum=%d\n",sum); //55
    return 0;
}


// int main(){
//     // 1 数组
//     //定义数组
//     int a[4]={1,2,3,4};
//     //赋值
//     int b[10]={12,23,4545,45};
//     int c[10]={};
//     c[0]=3;
//     printf("%d\n",c[0]);

//     //2.for(xx1,xx2,xx3) xx1初始化-->xx2判断-->xx3循环结束后++/--

//     //3.结构体 -- 一组数据有不同类型时，用结构体定义
// }