#include<stdio.h>
void main()
{
  int a[50],i,j,n,s,elmnt,l,r,mid,f=0,temp;
  printf("enter the elements of the array:");
  scanf("%d",&n);
  printf("enter the elements of the array:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  printf("enter the number to be searched:");
  scanf("%d",&elmnt);
  l=0;
  r=n-1;
  while(l<=r)
  {
    mid=(l+r)/2;
    if(a[mid]==elmnt)
    {
      printf("element is found");
      break;
    }
    else if(a[mid]>elmnt)
    {
      l=mid+1;
    }
    else
    {
      r=mid-1;
    }
  }
}
