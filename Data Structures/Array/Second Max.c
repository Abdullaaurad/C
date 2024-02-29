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
   
    double max1;     //largest number
    double max2;     //second largest number
    if(array[0]>array[1]){
        max1=array[0];
        max2=array[1];
    }
    else{
        max1=array[1];
        max2=array[0];
    }
   
    for(int i=2;i<n;i++){
        if(max1<array[i]){
            max2=max1;
            max1=array[i];
        }
        else if((max1>array[i]) && (max2<array[i])){
            max2=array[i];
        }
        else{
            continue;
        }
       
    }
    printf("The second largest of given number is %lf\n:",max2);
    return 0;
}
