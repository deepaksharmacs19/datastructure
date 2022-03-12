#include<stdio.h>
#include<string.h>
void _printAllCombinations(char *str,int start,int end)
{
char g;
int k;
if(start==end)
{
for(int i=0;i<end;i++)printf("%c",str[i]);
printf("\n");
return;
}
for(int i=start;i<end;i++)
{
for(k=start;k<i;k++) if(str[i]==str[k]) break;
if(k<i)continue;
g=str[i];
str[i]=str[start];
str[start]=g;
_printAllCombinations(str,start+1,end);
g=str[i];
str[i]=str[start];
str[start]=g;
}
}

void printAllCombinations(char *str)
{
_printAllCombinations(str,0,strlen(str));
}

int main()
{
char a[5];
printf("Enter a 4 characters string : ");
scanf("%s",a);
printAllCombinations(a);

return 0;
}