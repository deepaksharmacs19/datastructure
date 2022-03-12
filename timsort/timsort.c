#include<stdio.h>
#include<stdlib.h>

void mergeIt(int *x,int a,int mid,int b)
{
int lb1,lb2,lb3,ub1,ub2,ub3;
lb1=a;
lb2=mid+1;
ub1=mid;
ub2=b;
ub3=b;
lb3=a;
int tmp[b];
while(lb1<=ub1 && lb2<=ub2)
{
if(x[lb1]<=x[lb2])
{
tmp[lb3]=x[lb1];
lb1++;
}
else
{
tmp[lb3]=x[lb2];
lb2++;
}
lb3++;
}
while(lb1<=ub1)
{
tmp[lb3]=x[lb1];
lb1++;
lb3++;
}
while(lb2<=ub2)
{
tmp[lb3]=x[lb2];
lb2++;
lb3++;
}

lb3=a;
while(lb3<=ub3)
{
x[lb3]=tmp[lb3];
lb3++;
}

}




void sequenceOfMerge(int *x,int lb,int ub)
{
int ubInParts=64;
int lbInParts=0;
int i=2;
int ub2;
int upperBoundParts=ub/ubInParts;

while(i<=upperBoundParts)
{
while(lbInParts<=ub)
{
ub2=ubInParts*i;
if(ub2>ub) ub2=ub;
printf("Merge mein aaya\n");
printf("(%d, %d, %d)\n",lbInParts,lbInParts+64,ub2);
mergeIt(x,lbInParts,ubInParts,ubInParts*i);
lbInParts=ubInParts*i;
ubInParts=(ubInParts*i*2);
}
i+=2;
lbInParts=0;
ubInParts=(ubInParts*2);
}

}

void sortIt(int *x,int lb,int ub)
{
int j=0;
int lowerBound=0;
int upperBound=0;
int num,y;
while(upperBound!=ub)
{
lowerBound=upperBound;
upperBound=upperBound+64;
if(upperBound>ub) upperBound=ub;
printf("(%d, %d)",lowerBound,upperBound);
y=lowerBound+1;
while(y<upperBound)
{
num=x[y];
j=y-1;
while(j>=lowerBound && x[j]>num)
{
x[j+1]=x[j];
j--;
}
x[j+1]=num;
y++;
}
}
}


int main()
{
FILE *f;
int t,i;
f=fopen("File.data","w");
srand(34);
for(i=0;i<200;i++)
{
t=rand();
fwrite(&t,sizeof(int),1,f);
}
fclose(f);

f=fopen("File.data","r");
int arr[200];

fread(&arr,sizeof(int *),200,f);
sortIt(arr,0,200);
sequenceOfMerge(arr,0,200);
for(i=0;i!=200;i++) printf("%d, ",arr[i]);

return 0;
}