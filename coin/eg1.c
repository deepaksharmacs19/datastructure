#include<stdio.h>
#include<limits.h>

int voc[4]={1,2,5,10};
int coinCount=4;
int count=0;
int coinCounter(int coinValue)
{
int value=0;
int i=0;
int min=INT_MAX-1;
count++;
if(coinValue==0) return 0;
while(i<coinCount)
{
if(voc[i]<=coinValue)
{
value=coinCounter(coinValue-voc[i]);
if(value+1<min) min=value+1;
}
i++;
}
return min;
}

int main()
{
printf("Number of coins required to pay %d is %d\n",27,coinCounter(27));
printf("%d",count);
return 0;
}