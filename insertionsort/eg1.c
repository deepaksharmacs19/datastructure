#include<stdio.h>

int main()
{
int num,j;
int x[]={500, 250, 750, 1000, 2000, 25, 1, 2, 50, 249, 3000, 900, 875, 880, 800, 200, 600};
int count=0;
int y=1;
while(y<17)
{
count++;
num=x[y];
j=y-1;
while(j>=0 && x[j]>num)
{
count++;
x[j+1]=x[j];
j--;
}
x[j+1]=num;
y++;
}
for(y=0;y<17;y++) printf("%d, ",x[y]);
printf("\nCount : %d",count);
return 0;
}