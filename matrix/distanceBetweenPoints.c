#include<stdio.h>
#include<math.h>
int main()
{
int oep,iep,distance,smallest,countE,countF;
int x[10][2]={{10,1},{9,2},{8,3},{7,4},{6,5},{5,6},{4,7},{3,8},{2,9},{1,10}};
smallest=100;
oep=8;
iep=9;
for(int e=0;e<=oep;e++)
{
for(int f=e+1;f<=iep;f++)
{
distance=sqrt(((x[f][0]-x[e][0])*(x[f][0]-x[e][0]))+((x[f][1]-x[e][1])*(x[f][1]-x[e][1])));
if(distance<smallest)
{
smallest=distance;
countE=e;
countF=f;
}
}
}

printf("Closest points are (%d,%d) and (%d,%d) with distance : %d",x[countE][0],x[countE][1],x[countF][0],x[countF][1],smallest);

return 0;
}