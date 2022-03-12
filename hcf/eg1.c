#include<stdio.h>

int main()
{
int x,y,e;
int xA[10],yA[10];

printf("Enter a Number : ");
scanf("%d",&x);
printf("Enter Second Number : ");
scanf("%d",&y);
int i1=0;
int i2=0;
while(x!=1)
{
//printf("hello ");
e=2;
while(e<=9)
{
if(x%e==0)
{
x=x/e;
xA[i1]=e;
i1++;
e=2;
continue;
}
e++;
}
}
i2=0;
while(y!=1)
{
e=2;
while(e<=9)
{
if(y%e==0)
{
y=y/e;
yA[i2]=e;
i2++;
e=2;
continue;
}
e++;
}
}

for(e=0;e<i1;e++) printf("%d ",xA[e]);
printf("\n");
for(e=0;e<i2;e++) printf("%d ",yA[e]);

return 0;
}