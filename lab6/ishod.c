#include "main.h"

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
