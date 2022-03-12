#include<stdio.h>
int main()
{
int e,f,largest,v;
int x[]={12,3,92,-3,76,54,12,93,78};
int m[]={1,1,1,1,1,1,1,1};
largest=0;
e=0;
f=0;
while(f<8)
{
e=0;
while(e!=f)
{
v=m[e]+1;
if(x[e]<x[f] && v>m[f])
{
m[f]=v;
}
e++;
}
f++;
}
e=0;
while(e<8)
{
if(m[e]>largest)largest=m[e];
e++;
}
printf("%d",largest);
return 0;
}