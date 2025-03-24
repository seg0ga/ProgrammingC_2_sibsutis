#include <stdio.h>
#include <string.h>

struct Flight {
    char destination[10];
    int number;
    char type[10];};

int main() {
    int n,choice,searchNumber,found=0;
    struct Flight flight;
    char searchValue[10];
    FILE* file=fopen("Spravka.dat","wb");
    if (file==NULL) {
        printf("Ошибка при открытии файла для записи.\n");
        return 1;}

    printf("Введите количество записей: ");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Данные для рейса №%d:\n", i + 1);
        printf("Пункт назначения: ");
        scanf("%s", flight.destination);
        printf("Номер рейса: ");
        scanf("%d", &flight.number);
        printf("Тип самолета: ");
        scanf("%s", flight.type);
        fwrite(&flight,sizeof(struct Flight),1,file);
    }

    fclose(file);

    printf("Выберите поле для поиска:\n");
    printf("1)Пункт назначения\n");
    printf("2)Номер рейса\n");
    printf("3)Тип самолета\n");
    scanf("%d",&choice);


    printf("Введите значение для поиска: ");
    if (choice==1 || choice==3) {
        scanf("%s", searchValue);
    } else if (choice==2) {
        scanf("%d", &searchNumber);
    } else {printf("Неккоретное значение аргумента"); return 1;}

    file = fopen("Spravka.dat", "rb");
    if (file==NULL) {
        printf("Ошибка при открытии файла для чтения.\n");
        return 1;}

    while (fread(&flight,sizeof(struct Flight),1,file)) {
        if ((choice==1 && strcmp(flight.destination,searchValue)==0) || (choice==2 && flight.number==searchNumber) || (choice==3 && strcmp(flight.type,searchValue)==0)) {
            found = 1;
            printf("Данные найдены:\n");
            printf("Пункт назначения: %s\n",flight.destination);
            printf("Номер рейса: %d\n", flight.number);
            printf("Тип самолета: %s\n", flight.type);}}

    if (!found) {
        printf("Записи с таким значением не найдены.\n");}

    fclose(file);
}
