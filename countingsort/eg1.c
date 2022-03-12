#include<stdio.h>
#include<stdlib.h>
void countingSort(int *x,int lb,int ub)
{
int i,largest,index,data;
largest=x[0];
int *tmp;
int j=0;

for(i=0;i<=ub;i++)
{
if(largest<x[i]) largest=x[i];
}

tmp=(int *)malloc(sizeof(int)*(largest+1));
for(i=0;i<=largest;i++) tmp[i]=0;

for(i=0;i<=ub;i++)  
{
// logic for incrementing the data in tmp array according to the data in x array
index=x[i];
data=tmp[index];
data++;
tmp[index]=data;
}

for(i=0;i<=largest;i++)
{
index=tmp[i];
while(index>0)
{
x[j]=i;
index--;
j++;
}
}

}

int main()
{
int x[10];
int y;

for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

countingSort(x,0,9);

for(y=0;y<=9;y++) printf("%d\n",x[y]);

return 0;
}