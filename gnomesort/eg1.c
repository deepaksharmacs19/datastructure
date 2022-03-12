#include<stdio.h>

void gnomeSort(int *x,int lb,int ub)
{
int g;
for(int j=0;j<10;j++)
{
if(j==0) j++;
while(j>0)
{
if(x[j]<x[j-1])
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
else break;
}
}
}

int main()
{
int x[10],y;
for(y=0;y<10;y++) 
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}

gnomeSort(x,0,10);

for(y=0;y<10;y++) printf("%d\n",x[y]);

return 0;
}