#include <stdio.h>
#include <stdlib.h>

struct node { //узел
    int data;               
    struct node *next;      
    struct node *prev;      
    struct node *another;   
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL; 
    newNode->another = NULL; 
    return newNode;
}

void appendNode(struct node** head, int value) {
    struct node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; 
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void linkLists(struct node* list1, struct node* list2) {
    struct node* temp1 = list1;
    struct node* temp2 = list2;

    while (temp1 != NULL && temp2 != NULL) {
        temp1->another = temp2; 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

void navigateList(struct node* start) {
    struct node* current = start;
    char command;

    printf("Cтарт. Текущий элемент: %d\n", current->data);
    
    while (1) {
        printf("W/A/S/D или 8/4/2/6, Q для выхода: ");
        scanf(" %c", &command);

        if (command == 'Q' || command == 'q') {
            printf("Выход.\n");
            break;
        }

        switch (command) {
            case 'D': case '6': 
                if (current->next != NULL) {
                    current = current->next;
                    printf("Вправо. Текущий элемент: %d\n", current->data);
                } else {
                    printf("Конец списка. В начало? (Y/N): ");
                    char choice;
                    scanf(" %c", &choice);
                    if (choice == 'Y' || choice == 'y') {
                        current = start;
                        printf("Возврат. Текущий элемент: %d\n", current->data);
                    }
                }
                break;

            case 'A': case '4': 
                if (current->prev != NULL) {
                    current = current->prev;
                    printf("Влево. Текущий элемент: %d\n", current->data);
                } else {
                    printf("Начало списка.\n");
                }
                break;

            default:
                printf("Неверная команда.\n");
        }
    }
}

int main() {
    struct node* list1 = NULL; 
    struct node* list2 = NULL; 

    int value;

    printf("Элементы 1 списка (завершите 0):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        appendNode(&list1, value);
    }

    printf("Элементы 2 списка (завершите 0):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        appendNode(&list2, value);
    }

    
    printf("Первый список: ");
    printList(list1);

    printf("Второй список: ");
    printList(list2);

    linkLists(list1, list2);

    navigateList(list1);

    return 0;
}
