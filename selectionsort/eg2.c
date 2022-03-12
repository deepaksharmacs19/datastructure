#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void *left,void *right)
{
int *rightInt,*leftInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

void selectionSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,si;
void *g=malloc(es);
for(e=0;e<cs-1;e++)
{
si=e;
for(f=e+1;f<=cs-1;f++)
{
if(p2f(x+(es*f),x+(es*si))<0)
{
si=f;
}
}
memcpy(g,(const void *)x+(es*e),es);
memcpy(x+(es*e),(const void *)x+(es*si),es);
memcpy(x+(es*si),(const void *)g,es);
}
}



int main()
{
int *x;
int req;
int y;
printf("Enter Your Requirement : ");
scanf("%d",&req);

x=malloc(sizeof(int)*req);

for(y=0;y<req;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}

selectionSort(x,req,sizeof(int),myComparator);

for(y=0;y<req;y++) printf("%d\n",x[y]);

return 0;
}