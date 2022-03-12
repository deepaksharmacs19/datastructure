#include<stdio.h>

int main()
{
int x[]={23,43,-34,-3,54,-4};
int y,i,e,f;
f=0;
for(i=0;i<5;i++)
{
if(x[i]<0)
{
e=x[f];
x[f]=x[i];
x[i]=e;
f++;
}
}

for(i=0;i<5;i++) printf("%d\n",x[i]);

return 0;
}