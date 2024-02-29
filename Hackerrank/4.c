#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int m=(2*n)-1;
    int k=m-2;
  	for(int i=0;i<m;i++){
        printf("%d ",n);
    }
    printf("\n");
    for(int i=0;i<k;i++){
        printf("%d ",n);
        
        
        printf("%d ",n);
        printf("\n");
    }
    
    for(int i=0;i<m;i++){
        printf("%d ",n);
    }
    return 0;
}