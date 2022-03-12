#include<stdio.h>

int x[]={65,66,67,68,80,90};
int y[]={66,90,68,90};
int lenX=6;
int lenY=4;
int copies=0;
int store[6][4];

int lenOfLCS(int e,int f){
copies++;
int leftSide,rightSide;
if(e==lenX || f==lenY) return 0;
if(store[e][f]!=-1) return store[e][f];
if(x[e]==y[f]) return store[e][f]=1+lenOfLCS(e+1,f+1);
leftSide=lenOfLCS(e+1,f);
rightSide=lenOfLCS(e,f+1);
return store[e][f]=(leftSide>rightSide)?leftSide:rightSide;
}

int getLength()
{
for(int i=0;i<6;i++)
{
for(int e=0;e<4;e++)
{
store[i][e]=-1;
}
}
return lenOfLCS(0,0);
}

int main()
{
printf("%d\n",getLength());
printf("%d",copies);
return 0;
}