#include<iostream>
#include<utility>
#include<forward_list>
#include<stdio.h>
using namespace std;

int main()
{
forward_list<pair<int,int>> list;
int noel=0;
int prev,maxSS=0;
int x[8]={12,3,92,-3,76,54,12,93};
int flag[8]={0,0,0,0,0,0,0,0};
printf("The sequence is : ");
for(int i=0;i<8;i++) printf("%d, ",x[i]);
printf("\n");
printf("The indexes are  : ");
for(int i=0;i<8;i++) printf("%d   ",i);
printf("\n");
for(int i=0;i<7;i++)
{
noel=0;
if(flag[i]) continue;
prev=i;
for(int f=i+1;f<=7;f++)
{
if(x[prev]<x[f]) 
{
flag[f]=1;
prev=f;
noel++;
}
}
if(prev>i)
{
noel++;
if(noel<maxSS) continue;
if(noel>maxSS)
{
maxSS=noel;
list.clear();
} 
list.push_front(pair<int,int>(i,prev));
}
//printf("Number of Elements from %d to %d are %d \n",i,prev,noel);
}
for(pair<int,int> p:list)
{
cout<<"("<<p.first<<","<<p.second<<")"<<endl;
int i=p.first;
prev=i;
for(int f=i+1;f<=p.second;f++)
{
if(x[f]>x[prev])
{
printf("%d, ",x[prev]);
prev=f;
}
}
printf("%d\n",x[prev]);
}
return 0;
}