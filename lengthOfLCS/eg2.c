
#include<stdio.h>
#include<math.h>

void printSubsequence(char *str,int len)
{
int i=1;
char str2[]={'A','Y','B'};
int upperBoundStr2=(pow(2,3)-1);
char tmp2[3];

int lenX=len-1;
char tmp[len];
int tmpi=0;
int upperBoundStr=(pow(2,len)-1);
int j=0;
int p=0;
while(i<=upperBoundStr)
{
tmpi=0;
j=lenX;
while(j>=0)
{
p=i>>j;
if(p&1)
{
tmp[tmpi]=str[lenX-j];
tmpi++;
}
j--;
}


// inner comparison starts here
int iY=0;
int tmpY=0;
int lenY=3-1;
int jY=0;
int pY=0;
while(iY<=upperBoundStr2)
{
tmpY=0;
jY=lenY;
while(jY>=0)
{
pY=iY>>jY;
if(pY&1)
{
tmp2[tmpY]=str2[lenY-jY];
tmpY++;
}
jY--;
}

if(tmpi==tmpY)
{
int e=0;
for(e=0;e<tmpi;e++) if(tmp2[e]!=tmp[e]) break;
if(e==tmpi) for(e=0;e<tmpi;e++) printf("%c ",tmp[e]);
printf("\n");
}

iY++;
}

// inner comparison ends here

i++;
}

}

int main()
{
char s[4]={'A','B','C','D'};
printSubsequence(s,4);
return 0;
}