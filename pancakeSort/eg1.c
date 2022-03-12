#include<stdio.h>
#include<stdlib.h>

void flipArray(int *x,int lb,int ub)
{
int e,f,g;
for(e=lb,f=ub;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}

void sortWithPanCake(int *x,int lb,int ub)
{
int size=ub+1;
int i,largest,index;
while(size>0)
{
index=0;
largest=x[0];
for(i=1;i<size;i++) 
{
if(largest<x[i]){
index=i;
largest=x[i];
}
}
if(index==size) size--;
else{
flipArray(x,0,index);
flipArray(x,0,size-1);
size--;
}
}
}

int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

sortWithPanCake(x,0,9);

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}