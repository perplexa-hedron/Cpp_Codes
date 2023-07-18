#include<stdio.h>
int main()
{
    int val,arr[10],l=0,h=9,mid;
    printf("Enter the elements of array: ");
    for (int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value you want to search: ");
    scanf("%d",&val);
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==val)
        {
            printf("val is found at %d",mid);
                break;
        }
        else if(arr[mid]>val)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}