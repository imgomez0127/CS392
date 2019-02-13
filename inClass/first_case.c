#include<stdio.h>
union my_union{
	int x;
	char c;
};
int main(int argc, char** argv){
	union my_union yeet;
	yeet.x = 5;
	yeet.c = 'A';
	yeet.x = 6;
	int yah = 1;
	char str[] = "Hello World!";
	char str2[5];
	str2[0] = 'y';
	str2[1] = 'e';
	str2[2] = 'e';
	str2[3] = 't';
	printf("yeet\n");
	printf("current int in yeet %d \n", yeet.x);
	printf("%s\n",str);
	printf("%s\n",str2);	
	printf("\n");
	return 1;
}
