#include<stdio.h>

int x[41]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int count=0;

int fibo(int k)
{
count++;
if(k<=1) return k;
if(x[k]) return x[k];
x[k]=fibo(k-1)+fibo(k-2);
return x[k];
}

int main()
{
int k;
printf("Enter a number : ");
scanf("%d",&k);
printf("%d\n",fibo(k));
printf("Count : %d",count);
return 0;
}