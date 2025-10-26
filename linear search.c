#include <stdio.h>
void main()
{
    int i,flag=0,a[50],n,m;
    printf("Enter the number of elements:");
    scanf("%d",&m);
    printf("enter the elements of the array:");
    for (i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<m;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nenter the required number:");
    scanf("%d",&n);
    for (i=0;i<m;i++)
    {
        if(a[i]==n)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
    {
        printf("the number is present");
    }
    else
    printf("number is not present");
}