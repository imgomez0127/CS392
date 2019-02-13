#include <stdio.h>
int main(int argc, char ** argv){
	int index = 0;
	for(index; index < argc; ++index){
		printf("%s\n",argv[index]);
	}
	return 1;
}	
