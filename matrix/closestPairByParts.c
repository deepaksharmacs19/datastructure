#include<stdio.h>
#include<math.h>
int main()
{
int i,m,e,f,g1,g2,mid,oep,iep,countE[2],countF[2],smallest[2];
unsigned int distance;
int x[10][2]={{10,1},{9,2},{8,3},{7,4},{6,5},{5,6},{4,7},{3,8},{2,9},{1,10}};
i=0;

m=8;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[e][0]>x[f][0]) 
{
g1=x[f][0];
g2=x[f][1];
x[f][0]=x[e][0];
x[f][1]=x[e][1];
x[e][0]=g1;
x[e][1]=g2;
}
e++;
f++;
}
m--;
}

mid=10/2;

smallest[0]=100;
smallest[1]=100;
oep=mid-1;
iep=mid;
e=0;
while(i<2)
{
for(;e<=oep;e++)
{
for(int f=e+1;f<=iep;f++)
{
distance=sqrt(((x[f][0]-x[e][0])*(x[f][0]-x[e][0]))+((x[f][1]-x[e][1])*(x[f][1]-x[e][1])));
if(distance<smallest[i])
{
smallest[i]=distance;
countE[i]=e;
countF[i]=f;
}
}    //   inner for loop ends here
}    //   outer for loop ends here
i++;
e=mid+1;
oep=8;
iep=9;
}    //   Controller while loop ends here

printf("Closest pairs is (%d,%d) and (%d,%d) with distance : %d\n",x[countE[0]][0],x[countE[0]][1],x[countF[0]][0],x[countF[0]][1],smallest[0]);

printf("Closest pairs is (%d,%d) and (%d,%d) with distance : %d",x[countE[1]][0],x[countE[1]][1],x[countF[1]][0],x[countF[1]][1],smallest[1]);

printf("\n");

int finalSmallest=100;

int finalE,finalF;

e=0;
for(;e<=1;e++)
{
for(int f=0;f<2;f++)
{
distance=sqrt(((x[countE[e]][0]-x[countF[e]][0])*(x[countE[f]][0]-x[countE[e]][0]))+((x[countF[f]][1]-x[countE[e]][1])*(x[countF[f]][1]-x[countE[e]][1])));

if(distance<finalSmallest)
{
printf("%d\n",distance);
finalSmallest=distance;
finalE=countE[f];
finalF=countF[f];
}
}    //   inner for loop ends here
}    //   outer for loop ends here

printf("Final Closest pairs is (%d,%d) and (%d,%d) with distance : %d",x[finalE][0],x[finalE][1],x[finalF][0],x[finalF][1],finalSmallest);


return 0;
}