#include<stdio.h>
#define SIZE 100
int cirque[SIZE];
int front=-1,rear=-1;


int isFull(){
  return (front==0 && rear==SIZE-1)||(front==rear+1);
}

int isEmpty(){
  return(front==-1);
}

void enqueue(int x){
  if(isFull()){
    printf("queue is full\n");
  return;
  }
  if(isEmpty()){
    front=0;
    rear=(rear +1)%SIZE;
    cirque[rear]=x;
    printf("inserted value%d",cirque[rear]);
  }
  
}

void dequeue(){
  if (isEmpty()){
    printf("queue is empty");
  return;
  }
  else{
    printf("deleted:%d",cirque[front]);
    if(front==rear){
       front=rear=-1;
    }
    else{
       front=(front+1)%SIZE;
    } 
  }
}

void display(){
  if (isEmpty()){
    printf("queue is empty\n");
  return;
  }
  printf("circular queue elememts:");
  int i=front;
  while(1){
    printf("%d\t",cirque[i]);
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
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
    printf("\nenter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
       printf("\nenter the value:\n");
       scanf("%d",&value);
       enqueue(value);
       break;
     case 2:
       dequeue();
       break;
     case 3:
       display();
       break;
     case 4:
       printf("\nexiting\n");
       break;
     default:
       printf("\ninvalid choice\n");
   }
  }while(choice!=4);
  return 0;
}


