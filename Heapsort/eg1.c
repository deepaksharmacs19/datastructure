#include<stdio.h>

int main()
{
char x[]={'J','A','Y','G','A','N','E','S','H'};
char swi,lci,rci;

char g;
int y;
y=0;
int ri,ci;
ri=0;
while(y<9)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ri]<x[ci])
{
g=x[ri];
x[ri]=x[ci];
x[ci]=g;
ci=ri;
}
else break;
}
y++;
}

y=8;
while(y>0)
{
g=x[0];
x[0]=x[y];
x[y]=g;
y--;

ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y)swi=lci;
else{
if(x[rci]>x[lci]) swi=rci;
else swi=lci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else break;
}
}

for(y=0;y<9;y++) printf("%c\n",x[y]);

return 0;
}