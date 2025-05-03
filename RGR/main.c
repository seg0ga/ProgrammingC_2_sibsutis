#include "triangle.h"

int main(int argc, char *argv[]) {
    if (!validateInput(argc, argv)) {
        printUsage(argv[0]);
        return 1;}

    int n = parseInput(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "n должно быть положительным целым числом.\n");
        return 1;}

    int triangularNumber = triangularNumberRecursive(n);
    printf("Треугольное число для n = %d: %d\n", n, triangularNumber);

    printTriangleToFile(n);
    printf("Треугольник записан в файл triangle.txt\n");}