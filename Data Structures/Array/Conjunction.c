#include <stdio.h>
#include <stdlib.h>

int main(){
    int array1[5]={5,10,15,20,25};
    int array2[5]={30,35,40,45,50};
    int array3[10];

    printf("array 1 :[");
    for(int i=0;i<5;i++){
        if(i<4){
            printf("%d,",array1[i]);
        }
        else{
            printf("%d]",array1[i]);
        }
    }

    printf("\narray 2 :[");
    for(int i=0;i<5;i++){
        if(i<4){
            printf("%d,",array2[i]);
        }
        else{
            printf("%d]",array2[i]);
        }
    }

    printf("\narray 3 :[");
    int k=0;
    for(int i=0;i<10;i++){

        if(i<=4){
            array3[i]=array1[i];
        }
        else{

            array3[i]=array2[k];
            k++;
        }
    }
    for(int i=0;i<10;i++){
        if(i<9){
            printf("%d,",array3[i]);
        }
        else{
            printf("%d",array3[i]);
        }
    }
    printf("]");

}
