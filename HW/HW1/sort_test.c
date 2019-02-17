#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include"sort.h"
void printArr(int * intArr, int size){
	printf("[");
	for(int i = 0; i < size; i++){
		printf("%d ",intArr[i]);
	}
	printf("]\n");
}
int main(int argc, char ** argv){
	int arr1[1] = {5};
	int arr2[2] = {1000,5};
	int arr3[10] = {3,7,87,67,10,13,56,32,100,69};
	printArr(arr1,1);
	quickSort(arr1,1);
	printArr(arr1,1);
	printArr(arr2,2);
	quickSort(arr2,2);
	printArr(arr2,2);
	printArr(arr3,10);
	quickSort(arr3,10);
	printArr(arr3,10);
	return 1;
}
