#include<stdio.h>

int main()
{
int x[6]={1,3,5,6,9,7};
int found=0;
int si,ei,sum,reSum;
reSum=0;
sum=16;
si=0;
for(int i=0;i<6;i++)
{
if(x[i]==sum)
{
ei=i;
si=i;
found=1;
break;
}
ei=i;
reSum=reSum+x[i];
if(sum==reSum) 
{
found=1;
break;
}
if(reSum>sum)
{
reSum=reSum-x[si];
si++;
i=si;
}
}
if(found)
{
printf("The index of subarray is from %d to %d for sum %d and Numbers are : ",si,ei,sum);
for(;si<=ei;si++) printf("%d ",x[si]);
}
else printf("Subarray for sum %d is not found.",sum);

return 0;
}