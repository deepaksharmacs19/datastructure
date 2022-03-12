#include<stdio.h>

int main()
{
int x[10]={12,6,3,-7,-4,2,34,-6,-17,3};

int largest,z,e,f,size;
size=9;
largest=0;
for(e=0;e<=size;e++)
{
z=x[e];
if(largest<z) largest=z;
for(f=e+1;f<=size;f++)
{
z=z+x[f];
if(largest<z)largest=z;
}
}

printf("Largest : %d",largest);

return 0;
}