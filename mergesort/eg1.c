#include<stdio.h>

void mergeSort(int *x,int lb,int ub)
{
int top1=10;
int top2=10;
int mid,a,b;
top1--;
int stack1[10][2];
int stack2[10][2];
stack1[top1][1]=lb;
stack1[top1][2]=ub; 
while(top1!=10)
{
a=stack1[top1][1];
b=stack1[top1][2];

top1++;
top2--;
stack2[top2][1]=a;
stack2[top2][2]=b;
mid=(a+b)/2;
if(mid+1<b)
{
top1--;
stack1[top1][1]=mid+1;
stack1[top1][2]=b;
}
if(mid>a)
{
top1--;
stack1[top1][1]=a;
stack1[top1][2]=mid;
}
}

while(top2!=10)
{
int tmp[10];
int lb1,lb2,lb3,ub1,ub2,ub3;
a=stack2[top2][1];
b=stack2[top2][2];
top2++;
mid=(a+b)/2; 
lb1=a;
lb2=mid+1;
ub1=mid;
ub2=b;
lb3=a;
ub3=b;
while(lb1<=ub1 && lb2<=ub2)
{

if(x[lb1]<=x[lb2])
{
tmp[lb3]=x[lb1];
lb1++;
} 
else
{
tmp[lb3]=x[lb2];
lb2++;
}

lb3++;
}

while(lb1<=ub1)
{
tmp[lb3]=x[lb1];
lb1++;
lb3++;
}
while(lb2<=ub2)
{
tmp[lb3]=x[lb2];
lb2++;
lb3++;
}

lb3=a;
while(lb3<=ub3)
{
x[lb3]=tmp[lb3];
lb3++;
}

} 


} // function loop

int main()
{
int x[10];
int y;
y=0;
while(y<10)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
y++;
}

mergeSort(x,0,9);

y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}

return 0;
}