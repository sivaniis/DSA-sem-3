#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

void insertfront(struct node** head,int value){
  struct node* newNode = createNode(value);
  if(*head==NULL){
  newNode->next = *head;
  *head = newNode;
  }
  else{
    newNode->next=*head;
    (*head)->prev=*newNode;
    *head=newNode;
  }
}

void insertend(struct node** head,int value){
  struct node* newNode = createNode(value);
  if(head==NULL){
  newNode->next = *head;
  *head = newNode;
  return;
 }
struct node* temp=*head;
while (temp->next =NULL){
  temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfterValue(struct node** head, int key, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert after %d\n", key);
        return;
    }
    struct node* ptr = *head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    struct node* newNode = createNode(value);
    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }

    ptr->next = newNode;
}

