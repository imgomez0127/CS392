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
int findByteSize(FILE * fp){
	/*
	* FILE * fp: pointer to file that is going to be analyzed
	* This function takes in a file pointer and outputs the size of that file
	*/
	fseek(fp,0L,SEEK_END);
	int sz = ftell(fp);
	fseek(fp,0L,SEEK_SET);
	return sz;
}
int main(int argc, char ** argv){
if(argc != 3){
		printf("Usage ./sort <inputfile> <outputfile>\n");
		exit(1);
	}
	FILE *fp;
	char str[11];
	int sz;	
	int * numArr;
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot open file due to error %d\n",errno);
		exit(1);
	}
	sz = findByteSize(fp);
 	numArr = malloc(sz);	
	int lineCounter = -1;
	while(!feof(fp)){
		++lineCounter;
		fgets(str,sz,fp);	
		if(ferror(fp)){
			printf("There was an error while reading the file %d\n",errno);
			exit(1);
		}
		numArr[lineCounter] = atoi(str);	
	}
	fclose(fp);
	quickSort(numArr,lineCounter);
	printArr(numArr,100000);
	free(numArr);
	return 1;
}
