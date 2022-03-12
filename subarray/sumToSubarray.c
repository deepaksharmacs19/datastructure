#include<stdio.h>

int main()
{
int x[6]={1,3,5,6,8,7};
int found=0;
int si,ei,sum,reSum;
sum=13;
for(int e=0;e<5;e++)
{
si=e;
reSum=x[e];
if(reSum==sum)
{
found=1;
break;
}
for(int f=e+1;f<6;f++)
{
ei=f;
reSum=x[f]+reSum;
if(reSum==sum)break; 
}
if(reSum==sum)
{
found=1;
break; 
}
}

if(found){
printf("The SubArray is from index %d to %d with Numbers : ",si,ei); 
for(;si<=ei;si++) printf("%d, ",x[si]);
}
else printf("There is no SubArray for sum : %d\n",sum);

return 0;
}