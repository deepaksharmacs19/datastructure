#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

void linearSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
void *g;
int e,f;
g=(void *)malloc(es);

for(e=0;e<cs-1;e++)
{
for(f=e+1;f<=cs-1;f++)
{
if(p2f(x+(es*f),x+(es*e))<0)
{
memcpy(g,(const void *)(x+(es*f)),es);
memcpy(x+(es*f),(const void *)(x+(es*e)),es);
memcpy(x+(es*e),(const void *)g,es);
}
}
}
}
int main()
{
int *x;
int req;
int y=0;
printf("Enter Your Requirement : ");
scanf("%d",&req);
x=malloc(sizeof(int)*req);
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++) printf("%d\n",x[y]);

return 0;

}