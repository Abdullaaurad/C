#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer{
	char name[50];
	int account_number;
	int balance;
};

void checkbalance(int n,struct customer Arr[]){
	for(int i=0;i<n;i++){
		if(Arr[i].balance<200){
			printf("\%s   ",Arr[i].name);
		}
	}
}

void add(int n,struct customer Arr[]){
	for(int k=0;k<n;k++){
		if(Arr[k].balance>1000){
			Arr[k].balance=Arr[k].balance+100;
			printf("\ncustomer account number :%d",Arr[k].account_number);
			printf("\nNew balance :%d",Arr[k].balance);
		}
	}
}

int main(){
	printf("Enter the number of customers :");
	int n;
	scanf("%d",&n);
	struct customer Arr[n];
	
	for(int i=0;i<n;i++){
		printf("\nEnter customer name :");
		char word[50];
		scanf("%s",Arr[i].name);
		printf("Enter customer account number :");
		scanf("%d",&Arr[i].account_number);
		printf("Enter balance :");
		scanf("%d",&Arr[i].balance);
	}
	
	printf("name of the customer having balance less than 200 :");
	checkbalance(n,Arr);
	
	
	add(n,Arr);
}
