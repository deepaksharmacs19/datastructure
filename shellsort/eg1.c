//Hey guys in this video I am going to make a program of shell sort.
//And prior to make a shell sort algorithm I first make a insertion sort algorithm and then convert it to shell sort.

#include<stdio.h>

// some logical problem is there let's find it

int main()
{
int x[10],num,y,j,ub,lb,size,diff;
//ohh what a silly mistake I have done, not initialized lb and ub lol

lb=0;
ub=9;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

size=(ub-lb+1);
diff=size/2;

while(diff>=1)
{
y=lb+diff;
while(y<=ub)
{
j=y-diff;
num=x[y];
while(j>=0 && x[j]>num)
{
x[j+diff]=x[j];
j=j-diff;
}
x[j+diff]=num;
y=y+diff;
}
diff=diff/2;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
