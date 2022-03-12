#include<stdio.h>

//  The number which came in a subsequence are repeating itself that's why we have to buggify it.

int main()
{
int x[]={2,34,-2,45,4,23,6};
int flag[]={0,0,0,0,0,0,0};
int prev=0;
for(int i=0;i<7;i++)
{
if(flag[i]) continue;
prev=i;
for(int f=i+1;f<7;f++)
{
if(x[prev]<x[f])
{
printf("%d ",x[prev]);
prev=f;
flag[f]=1;
}
}
if(prev>i)printf("%d\n",x[prev]);
}


return 0;
}