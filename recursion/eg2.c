#include<stdio.h>

int m[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int count=0;

int power(int b,int c)
{
count++;
if(c==1) return b;
if(m[c]!=0) return m[c];
m[c]=(c%2==0) ? power(b,c/2)*power(b,c/2) : b*power(b,c/2)*power(b,c/2);
return m[c];
}

int main()
{
int num,pow;
printf("Enter a number : ");
scanf("%d",&num);
printf("Enter its power to find : ");
scanf("%d",&pow);
printf("%d\n",power(num,pow));
printf("%d Copies are made.",count);
return 0;
}