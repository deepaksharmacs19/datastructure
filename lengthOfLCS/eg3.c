#include<stdio.h>

int x[]={66,67,68,69,80,90};
int y[]={65,70,90};
int lenX=6;
int lenY=4;

int lenOfLCS(int e,int f){
int leftSide,rightSide;
if(e==lenX || f==lenY) return 0;
if(x[e]==y[f]) return 1+lenOfLCS(e+1,f+1);
leftSide=lenOfLCS(e+1,f);
rightSide=lenOfLCS(e,f+1);
return (leftSide>rightSide)?leftSide:rightSide;
}

int getLength()
{
return lenOfLCS(0,0);
}

int main()
{
printf("%d",getLength());
return 0;
}