#include<stdio.h>
#include<pthread.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int item1_counter=0, item2_counter=0, item3_counter=0;
pthread_mutex_t m1,m2,m3;
void * cs392_thread_run(void * file){
    /*
    *   Args:
    *       file (void *): A void pointer which can be type casted to a FILE pointer
    *   This function takes in a pointer that points to a file and increments and 
    *   decrements the respective counters as designated by each life of the file
    *   it does this concurrently through multithreading and ensures thread security
    *   through mutex locks
    */
    FILE * fp = (FILE *) file;
    char str[7];
    while(!feof(fp)){
        fgets(str,7,fp);
        if(strcmp(str,"-item1")==0){
            pthread_mutex_lock(&m1);
            item1_counter--;
            pthread_mutex_unlock(&m1);
        }
        else if(strcmp(str,"+item1")==0){
            pthread_mutex_lock(&m1);
            item1_counter++;
            pthread_mutex_unlock(&m1);
        }
        else if(strcmp(str,"-item2")==0){
            pthread_mutex_lock(&m2);
            item2_counter--;
            pthread_mutex_unlock(&m2);
        }
        else if(strcmp(str,"+item2")==0){
            pthread_mutex_lock(&m2);
            item2_counter++;
            pthread_mutex_unlock(&m2);
        } 
        else if(strcmp(str,"-item3")==0){
            pthread_mutex_lock(&m3);
            item3_counter--;
            pthread_mutex_unlock(&m3);
        }
        else if(strcmp(str,"+item3")==0){
            pthread_mutex_lock(&m3);
            item3_counter++;
            pthread_mutex_unlock(&m3);

        }
    }
    pthread_exit(NULL);
    return NULL;
}
int main(int argc, char ** argv){
    if(argc < 4){
        printf("Usage: ./cs392_thread fil1_path file2_path file3_path\n");
        return 1;
    }
    if(pthread_mutex_init(&m1,NULL) != 0){
        printf("\n mutex init 1 failed");
        exit(1);
    }
    if(pthread_mutex_init(&m2,NULL) != 0){
        printf("\n mutex init 2 failed");
        exit(1);
    }
    if(pthread_mutex_init(&m3,NULL) != 0){
        printf("\n mutex init 3 failed");
        exit(1);
    }
    pthread_t threads[3];
    FILE * fps[3]; 
    for(int i = 0; i < 3; ++i){
        fps[i] = fopen(argv[i+1],"r");
        if(fps[i] == NULL){
            printf("Cannot open file %s due to error %d\n",argv[i+1],errno);
            exit(1);
        }
        pthread_create(&threads[i],NULL,cs392_thread_run,(void *) fps[i]);
    }
    for(int i = 0; i < 3; ++i){
        pthread_join(threads[i],NULL);
        fclose(fps[i]);
    }
    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    pthread_mutex_destroy(&m3);
    printf("item1_counter: %d\n",item1_counter);
    printf("item2_counter: %d\n",item2_counter);
    printf("item3_counter: %d\n",item3_counter);
    return 0;
}
