#include <stdio.h>

int main() {
    int array[5]={10,20,30,40,50};
    printf("The element of the array are :[");
    for(int i=0;i<5;i++){
        printf("%d",array[i]);
        if(i<4){
            printf(",");
        }
        else{
            continue ;
        }
    }
    printf("]");
    
    
    int n; //the location of number that needs to be deleted
    printf("\nInput the location of the number that has to be deleted :");
    scanf("%d",&n);
    
    int k=n-1;
    while(k<5){
        array[k]=array[k+1];
        k++;
    }
        
    printf("updated array :[");
    for(int i=0;i<4;i++){
        printf("%d",array[i]);
        if(i<3){
            printf(",");
        }
        else{
            continue ;
        }
    }
    printf("]");

    return 0;
}
