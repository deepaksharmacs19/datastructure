#include<iostream>
#include<forward_list>
#include<utility>
using namespace std;

int main()
{
forward_list<pair<int,int>> list;
int si,ei,prev;
int noel,maxSS;
maxSS=0;


int x[]={2,34,-2,45,4,23,6};

int flag[]={0,0,0,0,0,0,0};
for(int i=0;i<7;i++)
{
noel=0;
if(flag[i]) continue;
si=i;
prev=si;
for(int f=i+1;f<7;f++)
{
if(x[prev]<x[f])
{
noel++;
prev=f;
flag[f]=1;
}
}
if(prev>i)
{
noel++;
ei=prev;
if(noel<maxSS) continue;
pair<int,int> p;
p.first=si;
p.second=ei;

if(noel>maxSS)
{
maxSS=noel;
list.clear();
}
list.push_front(p);
}

}

//for(list : pair<int,int> p)
auto i=list.begin();
pair<int,int> p;
for(;i!=list.end();++i)
{
p=*i;
cout<<p.first<<", "<<p.second<<endl;
si=p.first;
ei=p.second;

prev=si;
for(int f=si;f<=ei;f++)
{
if(x[si]<x[f])
{
printf("%d ",x[prev]);
prev=f;
}
}
if(prev>si)printf("%d\n",x[prev]);

}



return 0;
}