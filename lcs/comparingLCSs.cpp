#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int main()
{
int si,ei,prev;
int noel,maxSS;
maxSS=0;

queue<queue<pair<int,int>>> list;
queue<queue<pair<int,int>>> list1;
int x[]={2,34,-2,45,4,23,6};
int y[]={5,1,-2,45,4,23,6};
int flag[]={0,0,0,0,0,0,0};
int prevy=0;


for(int i=0;i<7;i++)
{
queue<pair<int,int>> queue,queue1;

noel=0;
if(flag[i]) continue;
si=i;
prev=si;
prevy=si;
for(int f=i+1;f<7;f++)
{
if(x[i]<x[f])
{
queue.push(pair<int,int>(prev,x[prev]));
noel++;
prev=f;
flag[f]=1;
}

if(y[i]<y[f])
{
queue1.push(pair<int,int>(prevy,y[prevy]));
prevy=f;
flag[f]=1;
}

}

if(prevy>i)
{
queue1.push(pair<int,int>(prevy,x[prev]));
list1.push(queue);
}
if(prev>i)
{
ei=prev;
queue.push(pair<int,int>(prev,x[prev]));
list.push(queue);
}
}

while(!list.empty())
{
queue<pair<int,int>> q=list.front();
list.pop();
 
while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<"("<<p.first<<")"<<p.second<<"  ";
}
cout<<endl;
}



return 0;
}