#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *function(void *_){
    char* message= (char*)_;
    for (int i=1;i<6;i++){
        printf(".поток %d  |  %s%d\n",i,message,i);
        sleep(1);}
    return NULL;
}


int main(){
    pthread_t thread[4];
    char* message[]={"qwerty1","qwerty2","qwerty3","qwerty4"};

    for (int i=0;i<4;i++){
        pthread_create(&thread[i], NULL,function,message[i]);}

    sleep(2);

    for (int i=0;i<4;i++){
        pthread_cancel(thread[i]);}
}