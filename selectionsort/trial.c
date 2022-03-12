#include<stdio.h>
int main()
{
int x[]={500, 250, 750, 1000, 2000, 25, 1, 2, 50, 249, 3000, 900, 875, 880, 800, 200, 600};
int e,f,g,y,count=0;
for(y=0;y<17;y++)
{
count++;
f=y;
for(e=y+1;e<17;e++)
{
count++;
if(x[e]<x[f])
{
f=e;
}

}
g=x[f];
x[f]=x[y];
x[y]=g;
}
for(y=0;y<17;y++) printf("%d, ",x[y]);
printf("\nCount : %d",count);
return 0;
}