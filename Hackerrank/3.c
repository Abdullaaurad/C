#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n=12345;
    int sum=0;
    for(int i=0;i<4;i++){
        int m=n%10;
        n=n/10;
        sum=sum+(m);
    }
    printf("%d",sum);
    return 0;
}