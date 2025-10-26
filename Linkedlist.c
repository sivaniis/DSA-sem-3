#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct Link {
	Node *front;
	Node *rear;
} Link;

void initLink(Link *link) {
	link->front = NULL;
	link->rear = NULL;
}

void insertRear(Link *link, int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	if (link->front == NULL && link->rear == NULL) {
		link->front = newNode;
		link->rear = newNode;
	} else {
		Node *temp = link->rear;
		link->rear = newNode;
		temp->next = newNode;
	}
	
	
}

void insertFront(Link *link, int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	if (link->front == NULL) {
		link->front = newNode;
		link->rear = newNode;
	} else {
		Node *temp = link->front;
		link->front = newNode;
 		newNode->next = temp;
	}
	
}

void insertAfter(Link *link, int key, int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	if (link->front == NULL) {
		printf("List is empty");
	} else {
		Node *current = link->front;
		while (current != NULL && current->data != key) 
			current = current->next;
		if (current == NULL) {
			printf("Key not found:");
			free(newNode);
			return;
		}
		Node *temp = current->next;
		current->next = newNode;
		if (temp == NULL) {	
			newNode->next =	NULL;
			link->rear = newNode;
		} else {
			newNode->next = temp;
		}
		
	}		
}

void deleteRear(Link *link) {
	if (link->front == NULL) {
		printf("List is empty");
	} else if (link->front == link->rear) {
		free(link->front);
		link->front = NULL;
		link->rear = NULL;
	
	} else {
		Node *current = link->front;
		while (current != NULL && current->next != link->rear) {
			current = current->next;
		}
		Node *temp = link->rear;
		current->next = NULL;
		link->rear = current;
		free(temp);
		
	}
}

void deleteFront(Link *link) {
	if (link->front == NULL) {
		printf("List is empty");
	} else if (link->front == link->rear) {
		free(link->front);
		link->front = NULL;
		link->rear = NULL;
	} else {
		Node *temp = link->front;
		link->front = link->front->next;
		free(temp);
	
	}

}
void deleteAt(Link *link, int key) {
    if (link->front == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (link->front->data == key) {
        Node *temp = link->front;
        if (link->front == link->rear) { 
            link->front = NULL;
            link->rear = NULL;
        } else {
            link->front = link->front->next;
        }
        free(temp);
        return;
    }
    Node *current = link->front;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Key not found.\n");
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    if (temp == link->rear) {
        link->rear = current;
    }
    free(temp);
}

void main() {
	Link *link;
	initLink(link);
	int choice;
	int val;
	int exit = 0;
	int pos;
	printf("1.insertFront \n 2.insertRear \n 3.insertAfter \n 4. deleteFront \n 5. deleteRear \n 6.deleteAt \n 7.display \n 8 exit.");
	while (exit == 0) {
		printf("Enter choice:");
		scanf("%d", &choice);
		Node *current = link->front;
		switch (choice) {
			case 1:
				printf("enter value:");
				scanf("%d", &val);
				insertFront(link, val);
				break;
			case 2:
				printf("enter value:");
				scanf("%d", &val);
				insertRear(link, val);
				break;
			case 3:
				printf("enter value:");
				scanf("%d", &val);
				printf("Enter value after:");
				scanf("%d", &pos);
				insertAfter(link, pos, val);
				break;
			case 4:
				deleteFront(link);
				break;
			case 5:
				deleteRear(link);
				break;
			case 6:
				printf("enter value to delete:");
				scanf("%d", &pos);
				deleteAt(link, pos);
				break;
			case 7:
				
				while (current != link->rear) {
					printf("%d", current->data);
					current = current->next;
				}
				printf("%d", link->rear->data);
				break;
			case 8:
				exit = 1;
				break;
			default:
				printf("Wrong choice, choose again.");
				break;
			
		}
	
	}
}
	
	
	
	
	
	






