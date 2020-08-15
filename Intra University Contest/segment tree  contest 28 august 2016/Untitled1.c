#include<stdio.h>

void merge(int ,int,int );
//void part(int,int);

int arr[30];

void part(int min,int max)
{
    int mid;
    if(min<max)
    {
        mid=(min+max)/2;
        part(min,mid);
        part(mid+1,max);
        merge(min,mid,max);
    }
}

void merge(int min,int mid,int max)
{
    int tmp[30];
    int i,j,k,m;
    j=min;
    m=mid+1;
    for(i=min; j<=mid &&m<=max ; i++)
    {
        if(arr[j]<=arr[m])
        {
            tmp[i]=arr[j];
            j++;
        }
        else
        {
            tmp[i]=arr[m];
            m++;
        }
    }
    if(j>mid)
    {
        for(k=m; k<=max; k++)
        {
            tmp[i]=arr[k];
            i++;
        }
    }
    else
    {
        for(k=j; k<=mid; k++)
        {
            tmp[i]=arr[k];
            i++;
        }
    }
    for(k=min; k<=max; k++)
        arr[k]=tmp[k];

}

int main()
{

    int i,size;
    printf("Enter total no. of elements : ");
    scanf("%d",&size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    part(0,size-1);
    printf("\nMerge sorted elements\n\n");
    for(i=0; i<size; i++)
        printf("%d ",arr[i]);
    return 0;
}
