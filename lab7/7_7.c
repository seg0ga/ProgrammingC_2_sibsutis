#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int turn = 0;

void* child_thread(void* _) {
    for (int i = 1; i < 6; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            if (turn == 1) break;
            pthread_mutex_unlock(&mutex);}

        printf("Дочер. поток: %d\n", i);
        turn = 0;
        pthread_mutex_unlock(&mutex);}
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, child_thread, NULL);

    for (int i = 1; i < 6; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            if (turn == 0) break;
            pthread_mutex_unlock(&mutex);}

        printf("Главн. поток: %d\n", i);
        turn = 1;
        pthread_mutex_unlock(&mutex);}

    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);
}
