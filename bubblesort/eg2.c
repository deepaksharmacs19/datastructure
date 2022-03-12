#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myComparator(void *left,void *right)
{
int *rightInt,*leftInt;
rightInt=(int *)left;
leftInt=(int *)right;
return (*leftInt)-(*rightInt);
}

void bubbleSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m;
void *g=malloc(es);
for(m=cs-2;m>=0;m--)
{
for(e=0,f=1;e<=m;e++,f++)
{
if(p2f(x+(es*f),x+(es*e))>0)
{
memcpy(g,(const void *)(x+(es*e)),es);
memcpy((x+(es*e)),(const void *)(x+(es*f)),es);
memcpy(x+(es*f),(const void *)g,es);
}
}
}
}

int main()
{
int *x;
int req,y;
printf("Enter Your Requirement : ");
scanf("%d",&req);
x=malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
bubbleSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++) printf("%d\n",x[y]);

return 0;
}