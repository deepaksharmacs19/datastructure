#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
int x[10]={10,-3,7,6,-2,4,3,9,-5,12};
int i=0,sum,si,ei,found,accumulatedSum;
map<int,int> t;

si=0;
accumulatedSum=0;
sum=5;
found=0;
map<int,int>::iterator iter=t.begin();
while(i<10)
{
ei=i;
accumulatedSum+=x[i];

if(accumulatedSum==sum) 
{
found=1;
break;
}
iter=t.find((accumulatedSum-sum));
if(iter!=t.end())
{
si=iter->second+1;
found=1;
break;
}
else
{
t.insert(pair<int,int>(accumulatedSum,i));
}

i++;
}

if(found) cout<<"SubArray is from "<<si<< " to "<<ei<<endl;
else cout<<"Not found"<<endl;
return 0;
}