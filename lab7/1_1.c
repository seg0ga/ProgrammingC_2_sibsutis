#include <stdio.h>
#include <pthread.h>

void *function(void *_){
    for (int i=1;i<6;i++){
        printf("Доч. поток %d\n",i);}
    return NULL;
}


int main(){
    pthread_t thread;
    pthread_create(&thread, NULL,function,NULL);
    for (int i=1;i<6;i++){
        printf("Род. поток %d\n",i);}
}