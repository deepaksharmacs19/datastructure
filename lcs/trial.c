#include<stdio.h>
//  The number which came in a subsequence are repeating itself that's why we have to buggify it.
int main()
{
int x[]={12,3,92,-3,76,54,12,93,78};
int prev=0;
int flag[]={0,0,0,0,0,0,0,0,0};
for(int i=0;i<8;i++)
{
if(flag[i]) continue;
prev=i;
for(int f=i+1;f<9;f++)
{
if(x[prev]<x[f])
{
printf("%d ",x[prev]);
flag[f]=1;
prev=f;
}
}
if(prev>i)printf("%d\n",x[prev]);
}


return 0;
}