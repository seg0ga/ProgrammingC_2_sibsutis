#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

struct Student{
    char name[64];
    int math,phy,inf,sum;};

struct Student addStudent(char *name, int math,int phy,int inf){
    struct Student newStudent;
    strncpy(newStudent.name,name,64);
    newStudent.math=math;
    newStudent.inf=inf;
    newStudent.phy=phy;
    newStudent.sum=math+inf+phy;
    return newStudent;
}

void printStudentInfo(struct Student student){
    printf("Имя: %s \n",student.name);
    printf("Математика: %d \n",student.math);
    printf("Информатика: %d \n",student.inf);
    printf("Физика: %d \n",student.phy);
    printf("Общий: %d \n",student.sum);
}

void printStudentInfoSort(struct Student student){
    printf("%s: %d\n",student.name,student.sum);
}

void generateRandomName(char name[64]){
    int len = rand() % 10 + 1;
    for (int i = 0; i < len; i++) {
        name[i]= 'a' + rand() % 26;}
    name[len]='\0';
}

void SelectSort(struct Student students[N]){
    for (int i=0;i<N;i++){
        int k = i;
        for (int j=i+1;j<N;j++){
            if (students[k].sum < students[j].sum){
                k=j;}}
    struct Student stud=students[i];
    students[i]=students[k];
    students[k]=stud;}
}

void CountingSort(struct Student students[], int n){
    int max_ball= 300;
    int counts[max_ball + 1];
    struct Student output[N];
    for (int i=0;i<=max_ball;i++) {
        counts[i]=0;}
    for (int i=0;i<n;i++) {
        counts[students[i].sum]++;}
    for (int i=1; i<=max_ball;i++) {
        counts[i]+= counts[i-1];}
    for (int i=n-1;i>=0;i--) {
        output[counts[students[i].sum] - 1] = students[i];
        counts[students[i].sum]--;}
    int j = 0;
    for (int i=n-1;i>=0;i--) {
            students[j] = output[i];
            j++;}
}

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
