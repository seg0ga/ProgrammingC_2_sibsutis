#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *sleepsort(void *_){
    int qwerty=*(int*)_;
    sleep(qwerty);
    printf("поток со временем %d завершился\n",qwerty);
    return NULL;
}

int main(){
    int arr[]={1,9,3,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    pthread_t thread[n];
    for (int i=0;i<n;i++){
        pthread_create(&thread[i],NULL,sleepsort, &arr[i]);
    }
    for (int i=0;i<n;i++){
        pthread_join(thread[i],NULL);
    }
}
