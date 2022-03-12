#include<stdio.h>

void cocktailSort(int *x,int lb,int ub)
{
int m,e,f,g,e1,f1,m1;
e1=0;
e=0;
m1=0;
m=ub-1;
while(m>=0)
{
if(m%2==0)
{
e=e1;
f=e+1;
while(e<=m)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
}
else 
{
m1++;
e1=e;
f1=e1-1;
while(e1>=m1)
{
if(x[e1]<x[f1])
{
g=x[e1];
x[e1]=x[f1];
x[f1]=g;
}
e1--;
f1--;
}
}
m--;
}

}

int main()
{
int x[10],y;

for(y=0;y<9;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}
cocktailSort(x,0,9);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}