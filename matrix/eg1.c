#include<stdio.h>

int main()
{
int x[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int y[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int z[4][4];
int e,f,g,j,num;
for(e=0;e<4;e++)
{
for(f=0;f<4;f++)
{
num=0;
for(g=0;g<4;g++)
{
num=num+(x[e][g]*y[g][f]);
}
z[e][f]=num;
}
}

for(e=0;e<4;e++)
{
printf("%d   ",e); 
for(g=0;g<4;g++)
{
printf("%d  ",z[e][g]);
}
printf("\n");
}
return 0;
}