#include "triangle.h"

int triangularNumberRecursive(int n) {
    if (n == 1) {
        return 1;}
    return n + triangularNumberRecursive(n - 1);}

bool validateInput(int argc, char *argv[]) {
    return argc == 3;}

int parseInput(char *n_str) {
    return atoi(n_str);}

void printTriangleToFile(int n, char *file) {
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Ошибка открытия файла %s для записи.\n",file);
        exit(1);}

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            fprintf(fp, "🟩 ");}
        fprintf(fp, "\n");}
    fclose(fp);}

void printUsage(char *programName) {
    fprintf(stderr, "Формат ввода: %s <n>\n", programName);}