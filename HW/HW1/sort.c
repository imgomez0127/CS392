#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include"sort.h"
int main(int argc, char ** argv){
	if(argc != 3){
		printf("Usage ./cat <inputfile> <outputfile>\n");
		exit(1);
	}
	FILE *fp;
	char * str;
	int sz;	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot open file due to error %d\n",errno);
		exit(1);
	}
	fseek(fp,0L,SEEK_END);
	sz = ftell(fp);
	str = malloc(sz);	
	fseek(fp,0L,SEEK_SET);
	fread(str,1,sz,fp);	
	fclose(fp);
	printf("\n");
	free(str);
	int * arr1 = [5];
	int * arr2 = [1000,5];
	int * arr3 = [3,7,87,67,10,13,56,32,100,69];
	return 1;
}
