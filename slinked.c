#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertfront(struct node** head, int value) {
    struct node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


void insertend(struct node** head, int value) {
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
}


void insertPosition(struct node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertfront(head, value);
        return;
    }
    struct node* newNode = createNode(value);
    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void deletefront(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteend(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void deletespecific(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deletefront(head);
        return;
    }
    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}


void search(struct node* head, int key) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found\n");
}

int main() {
    struct node* head = NULL;
    int choice, value, position, key;

    while (1) {
        printf("\n1. Insert Front\n2. Insert End\n3. Insert at Position\n4. Delete Front\n5. Delete End\n");
        printf("6. Delete Specific\n7. Search Element\n8. Display List\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertfront(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertend(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(&head, value, position);
                break;
            case 4:
                deletefront(&head);
                break;
            case 5:
                deleteend(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deletespecific(&head, position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

