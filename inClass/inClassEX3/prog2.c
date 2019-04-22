#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stddef.h>
int main(){
    key_t key = ftok("./",'A');
    int ShmID = shmget(key, 2*sizeof(int), 0666);
    void * buff = shmat(ShmID,NULL,0);
    int * array = (int *) buff;
    while(array[0] != 1){
    }
    array[1] = 1;
    shmdt(buff);
    return 0;
}
