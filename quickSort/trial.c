#include<stdio.h>


void quickSort(int *x)
{
int stack[17][2];
int top=17;
int count=0;
int e,f,ub,lb,pp,g;
pp=0;
g=0;
e=0;
f=0;
lb=0;
ub=17;
top--;
stack[top][0]=lb;
stack[top][1]=ub;
while(top!=17)
{
count++;
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
count++;
while(e<ub && x[e]<=x[lb])
{
count++;
e=e+1;
}
while(x[f]>x[lb])
{
count++;
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
printf("Count : %d\n",count);
}

int main()
{
int y=0;
int x[]={500, 250, 750, 1000, 2000, 25, 1, 2, 50, 249, 3000, 900, 875, 880, 800, 200, 600};
quickSort(x);
printf("\nAnd this is your Sorted array : \n");
y=0;
while(y<17)
{
printf("%d, ",x[y]);
y++;
}
return 0;
}