#include<stdio.h>
#define SIZE 100
int deque[SIZE];
int front=-1,rear=-1;


int isFull(){
  return (front==0 && rear==SIZE-1)||(front==rear+1);
}

int isEmpty(){
  return(front==-1);
}

void insertfront(int x){
  if(isFull()){
    printf("deque is full\n");
    return;  
  }
  if(isEmpty()){
    front=rear=0;
  }
  else if(front==0){
    front=SIZE-1;
  }
  else{
    front--;  
  }
  deque[front]=x;
}

void insertrear(int x){
  if(isFull()){
    printf("Deaue is full\n");
  return;
  }
  if(isEmpty()){
    front=rear=0;
  }
  else if(rear==SIZE-1){
    rear=0;
  }
  else{
    rear++;
  }
  deque[rear]=x;
}

void deletefront(){
  if (isEmpty()){
    printf("Deque is empty");
  return;
  }
  printf("deleted from front:%d",deque[front]);
  if(front==rear){
    front=rear=-1;
  }
  else if(front==SIZE-1){
    front=0;
  }
  else{
    front++;
  }
}


void deleterear(){
  if(isEmpty()){
    printf("deque empty");
    return;
  }
  printf("deleted from rear:%d",deque[rear]);
  if(front==rear){
    front=rear=-1;
  }
  else if(rear==0){
    rear=SIZE-1;
  }
  else{
    rear--;
  }
}


void display(){
  if (isEmpty()){
    printf("deque is empty\n");
  return;
  }
  printf("deque elememts:");
  int i=front;
  while(1){
    printf("%d\t",deque[front]);
    if(i==rear){
      break;
    }
    i=(i+1)%SIZE;
  }
  printf("\n");
}


int main(){
  int choice,value;
  do{
    printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n4. delete rear\n5. Display\n6. Exit");
    printf("\nenter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
       printf("\nenter the value:\n");
       scanf("%d",&value);
       insertfront(value);
       break;
     case 2:
       printf("\nenter the value:\n");
       scanf("%d",&value);
       insertrear(value);
       break;
     case 3:
       deletefront();
       break;
     case 4:
       deleterear();
       break;
     case 5:
       display();
       break;
     case 6:
       printf("\nexiting\n");
       break;
     default:
       printf("\ninvalid choice\n");
   }
  }while(choice!=6);
  return 0;
}

