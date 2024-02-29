#include <stdio.h>
int main() { 
	printf("Read n number of values in an array and display it in reverse order:\n");
	printf("------------------------------------------------------------------\n"); 
	
	int size;
	printf("Input the number of elements to store in the array :");
	scanf("%d",&size);
	printf("Input %d number of elements in the array :\n",size);
	int array[size];

	for(int i=0;i<size;i++){ 
		printf("element - %d :",i); 
		scanf("%d",&array[i]); 
	}
 
	printf("The Values stored into the array are :\n"); 
	for(int i=0;i<size;i++){ 
		printf("\t%d",array[i]);
 	}
 
	printf("\nThe value store into the array in reverse are :\n "); 
	
	for(int j=size-1;j>=0;j--){ 
		printf("\t%d",array[j]);
	} 
printf("\n");
return 0; 
}
