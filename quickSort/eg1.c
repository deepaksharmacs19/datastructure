#include<stdio.h>


void quickSort(int *x)
{
int stack[5][2];
int top=5;
int e,f,ub,lb,pp,g;
pp=0;
g=0;
e=0;
f=0;
lb=0;
ub=4;
top--;
stack[top][0]=lb;
stack[top][1]=ub;
while(top!=5)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])
{
e=e+1;
}
while(x[f]>x[lb])
{
f=f-1;
}
if(e<f)
{
g=x[f];
x[f]=x[e];
x[e]=g;
}
else 
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
pp=f;
}
}  //e<f
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}


}      //top is not equal to 5

}

int main()
{
int y=0;
int x[5];
while(y<5)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}

quickSort(x);
printf("\nAnd this is your Sorted array : \n");
y=0;
while(y<5)
{
printf("%d\n",x[y]);
y++;
}

return 0;
}