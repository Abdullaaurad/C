#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int Array[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(Array[j]>Array[j+1]){
                int temp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=temp;
            }
        }
    }
}

int main(){
    int Array[5]={1,2,3,4,5};
    BubbleSort(Array,5);
    for(int i=0;i<5;i++){
        printf("%d ",Array[i]);
    }

    return 0;
}
