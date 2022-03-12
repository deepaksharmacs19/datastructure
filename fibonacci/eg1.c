#include<stdio.h>

int main()
{
int x,y,z;
int j;
j=1;
x=0;
y=1;
while(j<=20)
{
printf("%d ",y);
z=x+y;
x=y;
y=z;
j++;
}
return 0;
}