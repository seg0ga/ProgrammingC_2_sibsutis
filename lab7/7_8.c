#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int THREADS,N,**A,**B,**C;

void* umnozhenie(void* _) {
    int thread_id=*(int*)_;
    int stroki=N/THREADS;
    int start=thread_id*stroki;
    int end=start+stroki;
    
    for (int i=start;i<end;i++) {
        for (int j=0;j<N;j++) {
            C[i][j]= 0;
            for (int k= 0; k<N;k++) {
                C[i][j]+=A[i][k]*B[k][j];}}}
}

int main(int argc, char* argv[]){

    N=atoi(argv[1]);
    THREADS=atoi(argv[2]);


    A=(int**)malloc(N*sizeof(int*));
    B=(int**)malloc(N*sizeof(int*));
    C=(int**)malloc(N*sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
        B[i] = (int*)malloc(N * sizeof(int));
        C[i] = (int*)malloc(N * sizeof(int));}

    for (int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    pthread_t threads[THREADS];
    int thread_ids[THREADS];
    for (int i=0;i<THREADS;i++) {
        thread_ids[i] =i;
        pthread_create(&threads[i], NULL, umnozhenie, &thread_ids[i]);}

    for (int i=0;i<THREADS;i++) {
        pthread_join(threads[i], NULL);}

    printf("Результат:\n");
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%d ",C[i][j]);
        }
    printf("\n");}

    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);free(B);free(C);
}
