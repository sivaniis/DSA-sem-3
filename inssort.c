#include<stdio.h>
void main()
{
  int a[50],i,j,n,min;
  printf("enter the number of elements of the array:");
  scanf("%d",&n);
  printf("enter the elements of the array:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  for(i=1;i<n;i++)
  {
    min=a[i];
    j=i-1;
    while(j>=0 && a[j]>min)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=min;
  }
  printf("the sorted array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
