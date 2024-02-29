#include <stdio.h>

int main() {
    int array[6]={10,20,30,40,50};
    printf("the elements of the array are:[");
    for(int i=0;i<5;i++){
        printf("%d,",array[i]);
    }
    
    printf("_]\nthe array has the size of 6");
    int k; //index of the number 
    int n; //number that needs to be inserted
    printf("\ninput the number that's needed to be inserted :");
    scanf("%d",&n);
    
    int l=4;
    if(n>=array[l]){
        k=l+1;
    }
    else if(n>=array[l-1]){
        k=l;
    }
    else if(n>=array[l-2]){
        k=l-1;
    }
    else if(n>=array[l-3]){
        k=l-2;
    }
    else if(n>=array[l-4]){
        k=l-3;
    }
    else{
        k=l-4;
    }
    
    for(int i=4;i>=k;i--){
        array[i+1]=array[i];
    }

    array[k]=n;
    printf("updated array :[");
    for(int i=0;i<=5;i++){
        printf("%d",array[i]);
        if (i<5){
            printf(",");
        }
        else{
            continue;
        }
    }
    printf("]");
    return 0;
}
