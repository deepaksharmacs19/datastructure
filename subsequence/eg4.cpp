#include<iostream>
#include<utility>
#include<queue>
#include<stdio.h>
using namespace std;

int main()
{
queue<queue<pair<int,int>>> list;
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
queue<pair<int,int>> queue;
if(flag[i]) continue;
prev=i;
for(int f=i+1;f<=7;f++)
{
if(x[prev]<x[f]) 
{
queue.push(pair<int,int>(prev,x[prev]));
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
while(!list.empty()) list.pop();
} 
queue.push(pair<int,int>(prev,x[prev]));
list.push(queue);
}
//printf("Number of Elements from %d to %d are %d \n",i,prev,noel);
}
while(!list.empty())
{
queue<pair<int,int>> q=list.front();
list.pop();

while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<"("<<p.first<<")"<<p.second<<",";
}
cout<<endl;
}
return 0;
}
