#include<stdio.h>

int main()
{
int y,num,found=0;
int si,ei,mid;
int x[11];
for(y=0;y<9;y++)
{
si=0;
ei=y;
printf("Enter a Number : ");
scanf("%d",&num);
while(si<=ei)
{
mid=si+((ei-si)/2);
if(x[mid]==num)
{
found=1;
break;
}
if(x[mid]<num) si=mid+1;
else ei=mid-1;
}
printf(" si : %d\n",si);
if(y==0)
{
x[0]=num;
}
else
{
int i=y;
while(i>=si)
{
x[i-1]=x[i];
i--;
}
x[si]=num;
}
}

for(y=0;y<9;y++)printf("%d\n",x[y]);

return 0;
}