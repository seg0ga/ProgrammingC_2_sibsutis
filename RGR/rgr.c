#include <stdio.h>
#include <stdlib.h>

int triangularNumberRecursive(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + triangularNumberRecursive(n - 1);}}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Формаь ввода: %s <n>\n", argv[0]);
        return 1;}

    char *n_str = argv[1];
    int n = atoi(n_str);

    if (n <= 0) {
        fprintf(stderr, "n должно быть положительным целым числом.\n");
        return 1;}
    int triangularNumber = triangularNumberRecursive(n);

    printf("Треугольное число для n = %d: %d\n", n, triangularNumber);

    FILE *fp = fopen("triangle.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Ошибка открытия файла triangle.txt для записи.\n");
        return 1;}

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            fprintf(fp, "🟩 ");}
        fprintf(fp, "\n");}
    fclose(fp);
    printf("Треугольникз аписан в файл triangle.txt\n");}
