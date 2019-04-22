#include<stdio.h>
#include<pthread.h>
int counter = 0;
pthread_spinlock_t lock;
void * run_thread(void * empty){
    int i = 0;
    pthread_spin_trylock(&lock);
    for( i = 0; i < 1000000; i++){
        counter++;
    }
    pthread_spin_unlock(&lock);
    pthread_exit(NULL);
    return NULL;
}
int main(){
    pthread_t tid,tid2;
    int e;
    e = pthread_spin_init(&lock,PTHREAD_PROCESS_SHARED);
    if(e != 0){
        printf("lock err\n");
        return 1;
    }
    e = pthread_create(&tid,NULL,run_thread,NULL);
    if(e != 0){
        printf("err");
        return 1;
    }
    e = pthread_create(&tid2,NULL,run_thread,NULL);
    if(e != 0){
        printf("err");
        return 1;
    }
    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);
    pthread_spin_destroy(&lock);
    printf("%d\n",counter);
    return 0;
}
