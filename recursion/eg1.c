#include<stdio.h>

int power(int constant,int p)
{
int sq=1;
if(p==1) return constant;
return constant*power(constant,p-1); 
}

int main()
{
int num,p;
printf("Enter a number : ");
scanf("%d",&num);
printf("Enter the power : ");
scanf("%d",&p);
printf("%d",power(num,p));
return 0;
}