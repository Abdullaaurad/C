#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements :");
    scanf("%d",&n);
   
    double array[n];
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++){
        printf("element - %d :",i);
        scanf("%lf",&array[i]);
    }
   
    double min=array[0];
    int position_of_min=1;
    for(int i=1;i<n;i++){
        if(min>array[i]){
            min=array[i];
            position_of_min=i+1;
        }
        else{
            continue;
        }
       
    }
    printf("The position of the smallest number is :%d\n",position_of_min);
}

