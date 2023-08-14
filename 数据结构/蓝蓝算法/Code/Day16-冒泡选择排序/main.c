#include <stdio.h>
//冒泡排序
// int n[10] = {25,35,68,79,21,13,98,7,16,62 };

void bulleSort(int arr[],int len){
    for(int i =0;i<len-1;i++){ //10个元素，比较9轮，也就是下标从0-8
        for(int j =0;j<len-1-i;j++){//随着轮次越多，比较次数越少，第一轮9次，第二轮8次  
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        printf("\n第%d轮比较之后排序\n",i+1);
        for(int k=0;k<len;k++){
            printf("%d\t",arr[k]);
        }
    }
    printf("\n冒泡排序结束后的排序:\n");
    for(int k=0;k<len;k++){
        printf("%d\t",arr[k]);
    }
}

//选择排序

int main(){
    int a[10]={25,35,68,79,21,13,98,7,16,62 };
    bulleSort(a,10);
}