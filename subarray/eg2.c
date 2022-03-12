#include<stdio.h>

int main()
{
int x[10]={12,34,5,-7,45,-23,5,45,6,3};
int local_max,global_max,size;
local_max=x[0];
global_max=x[0];
size=10;
for(int e=1;e<size;e++)
{
local_max=(local_max+x[e]>x[e])? local_max+x[e] : x[e];
global_max=(local_max>global_max)? local_max : global_max;
}
printf("%d",global_max);
return 0;
}