/*
* "I pledge my honor that I have abided by the Stevens honor system" - igomez1
* Author: Ian Gomez
* Date 02/15/19
*/
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include"sort.h"

void writeToFile(int * numArr, int size, char * fileName){
	/*
	* Args:
	* int * numArr: An array of numbers that is supposed to be written to the output file
	* int size: a value which holds the amount of elements in the array
	* char * fileName: name of the file that is supposed to be output to
	*/
	FILE * fp = fopen(fileName,"wb");
	if(fp == NULL){
		printf("Cannot open file due to error %d\n",errno);
		exit(1);
	}
	char newLine[1];
	newLine[0] = '\n';
	for(int i = 0; i < size; ++i){
		fwrite(&numArr[i],sizeof(int),1,fp);
		fputs(newLine,fp);
		if(ferror(fp)){
			printf("There was an error while writing to the file %d\n",errno);
			exit(1);
		}
	}
	fclose(fp);
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
	writeToFile(numArr,lineCounter,argv[2]);	
	free(numArr);
	return 1;
}
