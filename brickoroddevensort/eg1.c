#include<stdio.h>

void oddEvenSort(int *x,int lb,int ub)
{
int odd,even,swap,g;
while(1)
{
swap=0;
odd=lb+1;
even=lb+2;
while(odd<ub && even<ub)
{
if(x[odd]>x[even])
{
g=x[odd];
x[odd]=x[even];
x[even]=g;
swap++;
}
odd+=2;
even+=2;
}

even=lb;
odd=lb+1;
while(odd<ub && even<ub)
{
if(x[odd]<x[even])
{
g=x[odd];
x[odd]=x[even];
x[even]=g;
swap++;
}
odd+=2;
even+=2;
}
if(swap==0) break;
}

}

int main()
{
int x[10],y;

for(y=0;y<10;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}

oddEvenSort(x,0,10);

for(y=0;y<10;y++) printf("%d\n",x[y]);

return 0;
}