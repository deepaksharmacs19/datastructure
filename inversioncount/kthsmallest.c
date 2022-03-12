#include<stdio.h>

int kthSmallest(int *x,int ub,int index)
{
if(index>ub) return 0;
int e,g;
for(e=0;e<ub-1;e++)
{
for(int f=e+1;f<ub;f++)
{
if(x[f]<x[e])
{
g=x[f];
x[f]=x[e];
x[e]=g;
}
}
}
return x[index];
}

int main()
{
int x[]={34,5,67,2,65,3,65,8,2,3};
printf("%d",kthSmallest(x,10,3));
return 0;
}