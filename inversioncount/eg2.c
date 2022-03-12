#include<stdio.h>
#include<stdlib.h>
int merge(int *x,int lb,int mid,int ub,int *tmp)
{
int i1,i2,i3,count;
count=0;
i1=lb;
i2=mid+1;
i3=lb;

while(i1<=mid && i2<=ub)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
count=count+(mid-i1)+1;
i2++;
}
i3++;
}

while(i1<=mid)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=lb;
while(i3<=ub)
{
//printf("%d, ",tmp[i3]);
x[i3]=tmp[i3];
i3++;
}
return count;
}

int mergeSort(int *x,int lb,int ub,int *tmp)
{
int mid;
int count=0;
if(lb<ub)
{
mid=(lb+ub)/2;
count=count+mergeSort(x,lb,mid,tmp);
count=count+mergeSort(x,mid+1,ub,tmp);
count=count+merge(x,lb,mid,ub,tmp);
}
return count;
}

int inversionCountThroughMerge(int *x,int size)
{
int count,*tmp;
tmp=(int *)malloc(sizeof(int)*size);
count=mergeSort(x,0,size-1,tmp);
free(tmp);
return count;
}

 int main()
{
int x[10]={12,10,9,7,6,5,4,3,2,1};
printf("%d",inversionCountThroughMerge(x,10));
return 0;
}
