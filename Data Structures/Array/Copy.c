#include <stdio.h>

int main() {
    printf("Copy the elements one array into another array :\n");
    printf("------------------------------------------------\n");
    int size;
    printf("Input the number of elements to be stored in the array :");
    scanf("%d",&size);
    printf("\n Input %d elements in the array :\n",size);
   
    int array1[size];
    int array2[size];
   
    for(int i=0;i<size;i++){
        printf("element - %d :",i);
        scanf("%d",&array1[i]);
        array2[i]=array1[i];
    }
   
    printf("\nThe element stored in the first array are :\n");
   
    for(int i=0;i<size;i++){
        printf("\t%d",array1[i]);
    }  
    printf("\nThe element stored in the second array are :\n");
    for(int i=0;i<size;i++){
        printf("\t%d",array2[i]);
    }
    printf("\n");    
    return 0;
}
