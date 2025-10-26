#include<stdio.h>
#define MAX 100
struct term{
    int coeff;
    int expo;
};

void main()
{
  struct term poly1[MAX],poly2[MAX],res[MAX];
  int n1,n2,n3;
  int i,j,k;
  printf("enter number of terms of first polynomial:");
  scanf("%d",&n1);
  printf("enter the value of coefficeints and exponents:");
  for(i=0;i<n1;i++){
    scanf("%d%d",&poly1[i].coeff,&poly1[i].expo);
  }
  printf("enter number of terms of second polynomial:");
  scanf("%d",&n2);
  printf("enter the value of coefficeints and exponents:");
  for(i=0;i<n2;i++){
    scanf("%d%d",&poly2[i].coeff,&poly2[i].expo);
  }
  
  i=0;
  j=0;
  k=0;  
  while(i<n1 && j<n2){
    if(poly1[i].expo==poly2[j].expo){
      res[k].coeff=poly1[i].coeff+poly2[j].coeff;
      res[k].expo=poly1[i].expo;
      i++;
      j++;
      k++;
    }
    else if(poly1[i].expo>poly2[j].expo){
      res[k++]=poly1[i++];
    }
    else{
      res[k++]=poly2[j++];
    }
  }
  
  while(i<n1){
    res[k++]=poly1[i++];
  }
  while(j<n2){
    res[k++]=poly2[j++];
  }
  n3=k;
  
  printf("\nresultant polynomial is:\n");
  for(i=0;i<n3;i++){
    printf("%dx^%d",res[i].coeff,res[i].expo);
    if(i!=n3-1){
      printf("+");
    }
  }
      printf("\n");
}
