#include<stdio.h>

int main()
{
int x,y;
printf("Enter a Number : ");
scanf("%d",&x);
printf("Enter Another Number : ");
scanf("%d",&y);
int lower,lower2;
lower=x%y;
while(lower)
{
lower2=lower;
lower=y%lower;
if(lower==0) break;
y=lower2;
}
printf("HCF is : %d",lower2);
return 0;
}