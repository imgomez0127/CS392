#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
int main(int argc, char ** argv){
	if(argc != 2){
		printf("Usage ./cat <File Name>\n");
		exit(1);
	}
	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot open file due to error %d\n",errno);
		exit(1);
	}
	char * str[20];
	while(!feof(fp)){
		fread(str,20,1,fp);	
		if(ferror(fp)){
			printf("There was an error when reading the file %d\n" , errno);
			break;
		}
		printf("%s",str);
	}
	fclose(fp);
	printf("\n");
	return 1;
}
