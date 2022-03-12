#include<stdio.h>

void stoogeSort(int *x,int lb,int ub)
{
printf("(%d, %d)",lb,ub);
int g;
if(x[lb]>x[ub]) 
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
if((ub-lb)==2) return;
printf("something ");
if((ub-lb+1)>2)
{
stoogeSort(x,lb,(ub-ub/3));  // left
stoogeSort(x,ub/3,ub);  // right
stoogeSort(x,lb,(ub-ub/3));  // left
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
stoogeSort(x,0,9);
for(y=0;y<10;y++)printf("%d\n",x[y]);
return 0;
}