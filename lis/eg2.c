#include<stdio.h>
#include<math.h>

int main()
{
int x[]={65,66,67};
int upperBoundX,XEndPoint,e,j,num,lenX;
lenX=3;

upperBoundX=lenX-1;
XEndPoint=pow(2,lenX)-1;
num=1;
while(num<=XEndPoint)
{
for(e=upperBoundX;e>=0;e--)
{
j=num>>e;
if(j&1)printf("%c",x[upperBoundX-e]);
}
printf("\n");
num++;
}

return 0;
}