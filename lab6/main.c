#include "main.h"

int main(){
    clock_t start, end;
    start = clock();
    system("cat /proc/cpuinfo | grep 'model name' | head -n 1\n\n\n");
    struct Student students[N];
    srand(time(NULL));
    for (int i = 0;i<N;i++){
        char name[64];
        generateRandomName(name);
        int math =rand()%101;
        int phy =rand()%101;
        int inf =rand()%101;
        students[i] = addStudent(name,math,inf,phy);}

    for (int i=0;i<N;i++){
        printStudentInfoSort(students[i]);}
    
    printf("________________________________________________\n");
    CountingSort(students, N);
    for (int i=0;i<N;i++){
        printStudentInfoSort(students[i]);}
    printf("________________________________________________\n");
    end = clock();
    double time = end-start;
    printf("%.0f мс\n", time);
}
