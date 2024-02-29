#include<stdio.h>

void Increment(){
    static int count =0;
    printf("count is :%d\n",count);
    count++;
    if(count%9==0){
        printf("resetting count\n");
        count=0;
    }
}
int main(){
    for(int i=0;i<11;i++){
        Increment();
    }
    
}
