#include<stdio.h>
#include<stdlib.h>

int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[f];
x[f]=x[lb];
x[lb]=g;
}
}
return f;
}

void quickSort(int *x,int lowerBound,int upperBound)
{
int *lBound,*uBound;
int size;
size=(upperBound-lowerBound)-1;
lBound=(int*)malloc(sizeof(int)*size);
uBound=(int*)malloc(sizeof(int)*size);
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
pp=findPartitionPoint(x,lb,ub);

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
}      //top is not equal to 5
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

quickSort(x,0,req);
printf("\nAnd this is your Sorted array : \n");
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}

return 0;
}