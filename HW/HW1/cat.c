/*
* "I pledge my honor that I have abided by the Stevens honor system" - igomez1
* Author: Ian Gomez
* Date 02/15/19
* Description: thi is a Ian Gomez implementation of Linux cat
* it prints out the file contents
* ./cat <fileName>
* Date: 0-22-2019
* Author: Ian Gomez
*/
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
void fileCorrectlyOpen(FILE * fp){
	/*
	* FILE * fp: Pointer to file that has attempted to be open
	* This function checks if the file was successfuly opened and raises an error if it hasn't
	*/
	if(fp == NULL){
		printf("Cannot open file due to error %d\n",errno);
		exit(1);
	}
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
void printFile(char * str, FILE * fp,int sz){
	fread(str,1,sz,fp);	
	if(ferror(fp)){
		printf("There was an error when reading the file %d\n" , errno);
		exit(1);
	}
	printf("%s",str);
}
int main(int argc, char ** argv){
	if(argc != 2){
		printf("Usage ./cat <fileName>\n");
		exit(1);
	}
	FILE *fp;
	fp = fopen(argv[1],"r");
	fileCorrectlyOpen(fp);	
	char * str;
	int sz =findByteSize(fp);
	str = malloc(sz);
	printFile(str,fp,sz);	
	free(str);
	fclose(fp);
	return 1;
}
