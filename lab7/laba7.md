**Практическое задание 7. Знакомство с POSIX потоками**


**Оценка 3. Знакомство с pthread:**
1.	Создать поток

Написать программу, которая создает поток с помощью pthread_create(). Использовать атрибуты по умолчанию. Родительский и дочерний потоки должны вывести на экран по 5 строк текста.
```c
#include <stdio.h>
#include <pthread.h>

void *function(void *_){
    for (int i=1;i<6;i++){
        printf("Доч. поток %d\n",i);}
    return NULL;
}


int main(){
    pthread_t thread;
    pthread_create(&thread, NULL,function,NULL);
    for (int i=1;i<6;i++){
        printf("Род. поток %d\n",i);}
}
```
![{C67228B4-6444-44BE-B974-943928904AE8}](https://github.com/user-attachments/assets/733fb0d4-8343-4e43-aef0-0a7a1e7656a7)

2.	Ожидание потока

Модифицировать упр.1 так, что родительский поток выводит текст после завершения дочернего потока. Подсказка: pthread_join()
```c
#include <stdio.h>
#include <pthread.h>

void *function(void *_){
    for (int i=1;i<6;i++){
        printf("Доч. поток %d\n",i);}
    return NULL;
}


int main(){
    pthread_t thread;
    pthread_create(&thread, NULL,function,NULL);
    for (int i=1;i<6;i++){
        printf("Род. поток %d\n",i);}
    pthread_join(thread, NULL);
}
```
![{9723F0FF-A0C3-4604-989A-0DC3743CF8C4}](https://github.com/user-attachments/assets/86a8edcd-bc9b-474e-a33e-2e7f7bdead94)

3.	Параметры потока

Модифицировать упр.2 так, что основной поток создает 4 потока, исполняющих одну и ту же функцию. Эта функция должна распечатать последовательность текстовых строк, переданных как параметр. Каждый из созданных потоков должен распечатать различные последовательности строк.
```c
#include <stdio.h>
#include <pthread.h>

void *function(void *_){
    char* message= (char*)_;
    for (int i=1;i<6;i++){
        printf(".поток %d  |  %s%d\n",i,message,i);}
    return NULL;
}


int main(){
    pthread_t thread[4];
    char* message[]={"qwerty1","qwerty2","qwerty3","qwerty4"};

    for (int i=0;i<4;i++){
        pthread_create(&thread[i], NULL,function,message[i]);
        pthread_join(thread[i], NULL);}
}
```
![{889DC4E1-ABAC-4C2D-B857-4F2D27A2B17A}](https://github.com/user-attachments/assets/4b4e7d41-6d8c-4d92-b33a-2aa6b6d480e2)

4.	Завершение нити без ожидания

Добавить сон с помощью sleep() в функцию потоков между выводами строк. Спустя две секунды после создания дочерних потоков основной поток должен прервать работу всех дочерних потоков с помощью pthread_cancel().
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *function(void *_){
    char* message= (char*)_;
    for (int i=1;i<6;i++){
        printf(".поток %d  |  %s%d\n",i,message,i);
        sleep(1);}
    return NULL;
}


int main(){
    pthread_t thread[4];
    char* message[]={"qwerty1","qwerty2","qwerty3","qwerty4"};

    for (int i=0;i<4;i++){
        pthread_create(&thread[i], NULL,function,message[i]);}

    sleep(2);

    for (int i=0;i<4;i++){
        pthread_cancel(thread[i]);}
}
```
![{C3BF1DFA-FA81-48B5-966D-62DB30AAE524}](https://github.com/user-attachments/assets/ceff332e-cfa4-4a4b-bc60-b56e857a65b8)

5.	Обработать завершение потока

Модифицировать упр. 4 так, чтобы дочерний поток перед завершение распечатывал сообщение об этом. Использовать pthread_cleanup_push()
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void clean(void *_){
    char* message= (char*)_;
    printf("поток %s завершен\n",message);}

void *function(void *_){
    char* message= (char*)_;
    pthread_cleanup_push(clean,message);
    for (int i=1;i<6;i++){
        printf(".поток %d  |  %s%d\n",i,message,i);
        sleep(1);}
    pthread_cleanup_pop(0);
    return NULL;
}

int main(){
    pthread_t thread[4];
    char* message[]={"qwerty1","qwerty2","qwerty3","qwerty4"};

    for (int i=0;i<4;i++){
        pthread_create(&thread[i], NULL,function,message[i]);}

    sleep(2);

    for (int i=0;i<4;i++){
        pthread_cancel(thread[i]);}
    for (int i=0;i<4;i++){
        pthread_join(thread[i],NULL);}
}
```
![{CA0F026D-0989-4C7E-9442-A23A8F3EF3A2}](https://github.com/user-attachments/assets/4c2eda55-7527-47db-8289-044c3b58a3e7)

6. Реализовать простой Sleepsort

Реализовать прикольный алгоритм сортировки Sleepsort с асимптотикой O(N) (по времени). Суть алгоритма: на вход подается массив, пусть будет не более 50 элементов и пусть будет состоять из целочисленных значений. Для каждого элемента массива создается отдельный поток, в который в качестве аргумента передается значение элемента. Сам поток должен уйти в сон с помощью sleep() или usleep() с параметром равным аргументу потока (значение элемента массива), а после вывести на экран значение.
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *sleepsort(void *_){
    int qwerty=*(int*)_;
    sleep(qwerty);
    printf("поток со временем %d завершился\n",qwerty);
    return NULL;
}

int main(){
    int arr[]={1,9,3,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    pthread_t thread[n];
    for (int i=0;i<n;i++){
        pthread_create(&thread[i],NULL,sleepsort, &arr[i]);
    }
    for (int i=0;i<n;i++){
        pthread_join(thread[i],NULL);
    }
}
```
![{0BC58A4B-438B-4C88-BDAF-C81C37ADC970}](https://github.com/user-attachments/assets/d15b26ad-568a-47c3-b6ab-e8f7cd93485a)
