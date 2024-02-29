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
   
    double sum=0;
    for(int i=0;i<n;i++){
        sum=sum+array[i];
    }
     
    double mean=0;
    mean=sum/n;
    printf("Mean of the given number is :%.04lf\n",mean);
   
    return 0;
}
