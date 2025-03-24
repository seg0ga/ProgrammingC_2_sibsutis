#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc!=2) {
        printf("Не указаны все аргументы");
        return 1;}
        
    FILE *file=fopen(argv[1],"w");
    if (file==NULL){
        printf("Ошибка открытия файла");
        return 1;}

    fprintf(file, "  x  | sin(x) | tan(x)\n");
    fprintf(file, "_____|________|________\n");
    double x,y,z;
    for (x=0;x<=3.1;x+=0.1) {
        y=sin(x);
        z=tan(x);
        fprintf(file," %.1f |  %.2f  | %.3f\n", x, y, z);}
        
    if (fclose(file)!=0){
        printf("Ошибка закрытия файла");
        return 1;}
}
