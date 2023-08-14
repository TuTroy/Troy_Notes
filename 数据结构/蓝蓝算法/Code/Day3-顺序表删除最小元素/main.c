#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 50

typedef struct 
{
    int *data;
    int MaxSize, length;
} Seqlist;

// 初始化线性表
void init_Array(Seqlist* array){
    array->data = (int*)malloc(sizeof(int) * InitSize);
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    array->length = sizeof(values) / sizeof(values[0]);
    for(int i = 0; i < array->length; i++){
        array->data[i] = values[i];
    }
}

// 输出线性表
void PrintList(Seqlist *L){
    printf("顺序表中的元素为:\n");
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n\n");
}

// 线性表当前长度
int ListLength(Seqlist *L){
    return L->length;
}

int removeMinValue(Seqlist* sequence){
    if(sequence->length == 0){
        fprintf(stderr, "顺序表为空！\n");
        return -1;
    }

    int minInd = 0;
    int minVal = sequence->data[0];

    for(int i = 1; i < sequence->length; i++){
        if(sequence->data[i] < minVal){
            minVal = sequence->data[i];
            minInd = i;
        }
    }

    int deleteVal = sequence->data[minInd];
    sequence->data[minInd] = sequence->data[sequence->length - 1];
    sequence->length -= 1;
    return deleteVal;
}

int main(){
    Seqlist L;
    init_Array(&L);
    PrintList(&L);
    int minVal = removeMinValue(&L);
    printf("删除的最小元素为: %d\n", minVal);
    PrintList(&L);

    free(L.data); // Don't forget to free the allocated memory

    return 0;
}
