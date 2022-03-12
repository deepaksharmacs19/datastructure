#include<stdio.h>

//simple code of linear sort

int main()
{
int x[10],y,lb,ub;

for(y=0;y<10;y++) 
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

int e,f,g=0;
lb=0;
ub=10;

for(e=0;e<ub-1;e++)
{
for(f=e+1;f<ub;f++)
{
if(x[f]<x[e])
{
g=x[f];
x[f]=x[e];
x[e]=g;
}
}
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);

return 0;
}