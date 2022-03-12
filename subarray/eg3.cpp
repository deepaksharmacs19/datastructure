#include<stdio.h>

int main()
{
int x[10]={12,43,-3,4,-6,-3,34,53,5};
int lmax,gmax,i,j,si,ei;
lmax=gmax=x[0];
si=0;
for(i=1;i<10;i++)
{
j=lmax+x[i];
if(x[i]>j)
{
lmax=x[i];
si=i;
}
else lmax=j;
if(gmax<lmax)
{
gmax=lmax;
ei=i;
}
}
printf("(%d-%d)--->%d\n",si,ei,gmax);
}