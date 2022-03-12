#include<stdio.h>

void heapSort(int *x,int lb,int ub)
{
int es=sizeof(int);
x=&x[0]+(es*lb);
int ri,ci,y;
int swi,lci,rci,g;
y=0;
while(y>ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else break;
}
y++;
}

y=ub-1;
while(y>lb)
{
g=x[y];
x[y]=x[lb];
x[lb]=g;
y--;

ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else 
{
if(x[rci]>x[lci])
{
swi=rci;
}
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
}

int main()
{
int x[10];
for(int i=0;i<9;i++) 
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
heapSort(x,4,9);
for(int i=0;i<9;i++) 
{
printf("%d\n",x[i]);
}
return 0;
}