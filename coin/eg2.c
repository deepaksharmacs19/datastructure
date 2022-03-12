#include<stdio.h>
#include<limits.h>

int voc[3]={2,3,5};
int vocCount=3;

int getMinCoins(int value)
{
int arr[vocCount+1][value+1];
int a;
int num=0;
for(int i=0;i<=value;i++) arr[0][i]=INT_MAX-1;
for(int i=0;i<=vocCount;i++)arr[i][0]=0;

for(int i=1;i<=vocCount;i++)
{
a=voc[i-1];
for(int e=1;e<=value;e++)
{
if(a>e)
{
arr[i][e]=arr[i-1][e];
continue;
}
num=arr[i][e-a];
arr[i][e]=(num+1)<arr[i-1][e]?(num+1):arr[i-1][e];
}
}
for(int i=0;i<=vocCount;i++) 
{
for(int e=0;e<=value;e++)
{
printf("%d ",arr[i][e]);
}
printf("\n");
}



int val=arr[vocCount][value];

for(int i=vocCount;val>0 && i>0;i--)
{
val=arr[i][value];
for(int e=value;val>0 && e>=0;e-=voc[i-1])
{
if(arr[i][e-voc[i-1]]==(val-1) && arr[i][e-voc[i-1]]!=INT_MAX-1 && (e-voc[i-1])>0)
{
val--;
printf("%d ",voc[i-1]);
}
if(arr[i][e-voc[i-1]]==INT_MAX-1 || (e-voc[i-1])<=0)
{
i--;
//e+=voc[i-1];   // Bug is there
}

printf("(%d)",e);
if(val==0) break;
}
}
}



int main()
{
getMinCoins(9);
return 0;
}