#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
    struct node *dop;};

typedef struct node node_t;

node_t *newNode(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->dop = NULL;
    return new_node;
}

void printList(node_t *head) {
    printf("Список: ");
    node_t* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;}
    printf("\n");
}

node_t* appendBack(node_t* head, int data){
    node_t* new_node = newNode(data);
    if (head == NULL) {
        return new_node;}
    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;}
    cur->next = new_node;
    return head;
}

int navigate(node_t *start) {
    node_t *current_main = start;
    node_t *current_dop = NULL;
    bool in_dop_list = false;
    char command;

    while (1) {
        if (in_dop_list) {printf("Текущее значение: %d\n", current_dop->data);}
        else {printf("Текущее значение: %d\n", current_main->data);}
        scanf(" %c",&command);
        switch (command) {
            case 'D': case 'd': case '6':
                if (in_dop_list) {
                    if (current_dop->next!=NULL) {
                        current_dop=current_dop->next;
                    } else {
                        printf("Достигнут конец\n");}
                } else {
                    if (current_main->next!=NULL) {
                        current_main=current_main->next;
                    } else {
                        printf("Достигнут конец\n");}
                }break;

            case 'S': case 's': case '2':
                if (!in_dop_list&&current_main->dop!=NULL) {
                    current_dop=current_main->dop;
                    in_dop_list=true;
                } else {
                    printf("Достигнут конец\n");
                } break;
            
            case 'Q': case 'q':
                return 0;
            default:
                printf("Неизвестная команда.\n");}}}

int main() {
    node_t *head=NULL;
    node_t *dop_head=NULL;
    int k=1;

    while (true) {
        int a;
        printf("Введите %d значение основного списка: ", k);
        scanf("%d", &a);
        if (a==0) {
            break;
        }
        head=appendBack(head,a);
        k++;}

    k=1;
    while (true) {
        int a;
        printf("Введите %d значение связнного списка: ", k);
        scanf("%d", &a);
        if (a==0) {
            break;}
    
        dop_head=appendBack(dop_head,a);
        k++;}

    if (head!=NULL&&dop_head!=NULL) {
        node_t *cur_main=head;
        node_t *cur_dop=dop_head;

        while (cur_main!=NULL&&cur_dop!=NULL) {
            cur_main->dop=cur_dop;
            cur_main=cur_main->next;
            cur_dop=cur_dop->next;}}

    printf("Основной список:\n");
    printList(head);

    printf("Связанный список:\n");
    printList(dop_head);

    navigate(head);
}
