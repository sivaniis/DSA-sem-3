#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
void enqueue(int val){
  if (rear==SIZE-1){
    printf("queue overflow");
  }
  else if(rear==-1&& front==-1){
    front=rear=0;
    queue(rear)=value;
  }
  else{
    printf(queue[front]);
    front++;
  }
}

void display(){
  if(front==-1 && rear==-1){
    printf("queue empty");
  }
  else{
     printf("queue is:");
     for(int i=front;i<=rear;i++){
      printf(queue[i]);
     }
     printf("\n");
  }
}

void dequeue(){
   if(front==-1 || front>rear){
     printf("queue underflow");
    }
   else{
     int item=queue[front];
     if(front==rear){
      front=rear=-1;     
     }
     else{
       front+=1;
     }
     printf("the value is:",item);
}


int main(){
  int choice,value;
  while(1)
    printf("\n 1 enqueue\n2 dequeue\n3display");
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("enter the value:");
        scanf("%d",&value);
        enqueue(value);
        break;
     case 2:
        dequeue();
        break;
     case 3:
        display();
        break;
}
