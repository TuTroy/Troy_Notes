//接受一个只包括小写字母的字符串，然后输出反转之后的字符串，字符串长度不超过1000
// #include <stdio.h>
// #include <string.h>
// int main(){
//     char string1[20]="aabcd";
//     char string2[20];
//     int j=sizeof(string1);
//     for(int i=0;i<sizeof(string1);i++){
//         string2[i]=string1[j-i-1];
//         printf("%c",string2[i]); //输出dcbaa
//     }
//     printf("\n");
// }

//答案
#include <stdio.h>
#include <string.h>
//定义一个翻转函数
char* solve(char* str){
    char *p1 = str;
    char *p2 = str;
    int temp =0;
    while(*p2!='\0'){
        p2++;
    }
    p2--;
    while(p1<p2){
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2--;
    }
    return str;
}
int main(){
    char str[20];
    printf("输入一串字符串：");
    scanf("%s \n",str); //数组不带&,本身就是地址
    char *v = solve(str);
    printf("%s\n",v);
    return 0;
}