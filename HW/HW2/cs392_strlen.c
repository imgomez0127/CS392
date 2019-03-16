#include "cs392_string.h"
#include <stdio.h>
unsigned int cs392_strlen(char *str){
    unsigned int length = 0;
    for(unsigned i = 0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}
int main(){
    char * hello_world = "hello world!";
    printf("'hello world!' length: %d \n",cs392_strlen(hello_world));
    return 0;
} 
