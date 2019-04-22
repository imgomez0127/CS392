#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stddef.h>
int main(){
    key_t key = ftok("./",'A');
    int ShmID = shmget(key, 2*sizeof(int), IPC_CREAT | 0666);
    int * buff = shmat(ShmID,NULL,0);
    int * array = (int *) buff;
    array[0] = 0;
    array[1] = 0;
    array[0] = 1;
    while(array[1] != 1){
    }     
    shmdt(buff);
    shmctl(ShmID,IPC_RMID,NULL);
    return 0;
}
