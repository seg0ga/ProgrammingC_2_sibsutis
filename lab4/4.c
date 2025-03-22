#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc!=2) {
        perror("Не указаны все аргументы");
        return 1;}
        
    FILE *output_file=fopen(argv[1],"w");
    if (!output_file){
        perror("Ошибка открытия файла");
        return 1;}

    fprintf(output_file, "  x  | sin(x) | tan(x)\n");
    fprintf(output_file, "----------------------\n");
    double x,y,z;
    for (x=0;x<=3.1;x+=0.1) {
        y=sin(x);
        z=tan(x);
        fprintf(output_file," %2.1f | %5.2f  | %5.3f\n", x, y, z);
    }
    fclose(output_file);
}
