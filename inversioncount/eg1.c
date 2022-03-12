#include<stdio.h>

int main()
{
int count=0;
int x[]={100,90,70,60,50,40,30,20,10,4}; //21
for(int e=0;e<=8;e++)
{
for(int f=e+1;f<=9;f++)
{
if(x[e]>x[f]) count++;
}
}
printf("InversionCount is : %d",count);
return 0;
}