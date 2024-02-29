#include <stdio.h>

int main() {
    int array[6]={10,20,30,40,50};
    printf("the elements of the array are:[");
    for(int i=0;i<5;i++){
        printf("%d,",array[i]);
    }
    printf("_]\nthe array has the size of 6");
    int k; //location of the number to be inserted
    int n; //number that needs to be inserted
    
    printf("\ninput the number that's needed to be inserted :");
    scanf("%d",&n);
    printf("input the numbers location :");
    scanf("%d",&k);
    
    for(int i=4;i>=k-1;i--){
	    array[i+1]=array[i];
    }

    array[k-1]=n;
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
