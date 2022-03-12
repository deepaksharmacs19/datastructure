#include<stdio.h>

int main()
{
int noel=0;
int prev;
int x[8]={3,4,3,5,7,54,32,-4};
int flag[8]={0,0,0,0,0,0,0,0};
printf("The sequence is : ");
for(int i=0;i<8;i++) printf("%d, ",x[i]);
printf("\n");
printf("The indexes are  : ");
for(int i=0;i<8;i++) printf("%d   ",i);
printf("\n");
for(int i=0;i<7;i++)
{
noel=0;
if(flag[i]) continue;
prev=i;
for(int f=i+1;f<=7;f++)
{
if(x[prev]<x[f]) 
{
flag[f]=1;
printf("%d, ",x[prev]);
prev=f;
noel++;
}
}
if(prev>i)
{
noel++;
printf("%d\n",x[prev]);
}
printf("Number of Elements from %d to %d are %d \n",i,prev,noel);
}

return 0;
}