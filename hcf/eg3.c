#include<stdio.h>

int getHCF(int p,int q)
{
if(q==0) return p;
getHCF(q,p%q);
}

int main()
{
int p, q;
printf("Enter a Number : ");
scanf("%d",&p);
printf("Enter another number : ");
scanf("%d",&q);
printf("%d",getHCF(p,q));
return 0;
}