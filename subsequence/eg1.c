#include<stdio.h>

int main()
{
int x[8]={34,5,2,5,-3,4,5,3};
int flag[8]={0,0,0,0,0,0,0,0};
int prev;
for(int e=0;e<7;e++)
{
prev=e;
if(flag[e]) continue;
for(int f=e+1;f<8;f++)
{
if(x[prev]<x[f])
{
printf("%d ",x[prev]);
prev=f;
flag[f]=1;
}
}
if(prev>e) printf("(%d)\n",x[prev]);
}

return 0;
}