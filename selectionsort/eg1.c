#include<stdio.h>

int main()
{
int x[10];
int y;
for(y=0;y<10;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

int e,f,g;
for(y=0;y<9;y++)
{
f=y;
for(e=y+1;e<=9;e++)
{
if(x[e]<x[f])
{
f=e;
}

}
g=x[f];
x[f]=x[y];
x[y]=g;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}