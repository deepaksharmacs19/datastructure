#include<stdio.h>


int main()
{
int x[]={2,34,-2,45,4,23,46};
int m[]={1,1,1,1,1,1,1};

int f=1;
for(int i=0;f<7;i++)
{
if(i==f)
{
i=0;
f++;
}
if(x[i]<x[f])
{
if((m[i]+1)>m[f]) m[f]=m[i]+1;
}
}

int max=m[0];
for(int i=0;i<7;i++) printf("%d, ",m[i]);
//if(max<m[i])max=m[i];


return 0;
}