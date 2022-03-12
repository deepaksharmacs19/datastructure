#include<stdio.h>

int main()
{
int x[10];
int y=0;
int m=8;
int e,f;

while(y<=9)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
int g;
for(;m>=0;m--)
{
for(e=0,f=1;e<=m;e++,f++)
{
if(x[f]<x[e])
{
g=x[f];
x[f]=x[e];
x[e]=g;
}
}
}
for(y=0;y<9;y++) printf("%d\n",x[y]);

return 0;
}