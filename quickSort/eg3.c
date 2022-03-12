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

int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f((x+(e*es)),(x+(lb*es)))<=0) e++;
while(p2f((x+(f*es)),(x+(lb*es)))>0) f--;
if(e<f)
{
memcpy(g,(const void *)(x+(e*es)),es);
//g=x[e];
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
//x[e]=x[f];
memcpy((x+(f*es)),(const void *)g,es);
//x[f]=g;
}
else
{
memcpy(g,(const void *)(x+f*es),es);
memcpy(x+(f*es),(const void *)(x+(lb*es)),es);
memcpy((x+(lb*es)),(const void *)g,es);
}
}
free(g);
return f;
}

void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int *lBound,*uBound;
int size;
size=(upperBound-lowerBound)-1;
lBound=(int *)malloc(size);
uBound=(int *)malloc(size);
int top=size;
int ub,lb,pp;

pp=0;
lb=0;
ub=size;

top--;
lBound[top]=lb;
uBound[top]=ub;
while(top!=size)
{
lb=lBound[top];
ub=uBound[top];
top++;
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub)
{
top--;
lBound[top]=pp+1;
uBound[top]=ub;
}
if(lb<pp-1)
{
top--;
lBound[top]=lb;
uBound[top]=pp-1;
}
}      
free(lBound);
free(uBound);
}

int main()
{
int y=0,req;

int *x;
printf("Enter your requirement : ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
if(x==NULL) printf("Unable to allocate memory : \n");
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}

quickSort(x,0,req,sizeof(int),myComparator);
printf("\nAnd this is your Sorted array : \n");
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}