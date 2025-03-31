#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

struct Student{char name[64];int math,phy,inf,sum;};

struct Student addStudent(char *name, int math,int phy,int inf);
void printStudentInfo(struct Student student);
void printStudentInfoSort(struct Student student);
void generateRandomName(char name[64]);
void SelectSort(struct Student students[N]);
void CountingSort(struct Student students[], int n);
