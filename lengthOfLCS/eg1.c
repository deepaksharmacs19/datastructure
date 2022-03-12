#include<stdio.h>
#include<math.h>
void printSubsequence(char *str,int len)
{
int i=1;
int lenX=4;
int upperBoundStr=(pow(2,lenX)-1);

int j=0;
int p=0;
while(i<=upperBoundStr)
{
j=lenX-1;
while(j>=0)
{
p=i>>j;
if(p&1)printf("%c",str[3-j]);
j--;
}
printf("\n");
i++;
}

}

int main()
{
char s[4]={'A','B','C','D'};
printSubsequence(s,4);
return 0;
}