#include<stdio.h>
#include<stdlib.h>

void sortAll(int size)
{
int y,x[10],smallest,index,pos,g;
char e[15];
FILE *file[10],*f;
f=fopen("mainFile.d","wb");
for(y=0;y<=9;y++) 
{
sprintf(e,"Files%d.data",y);
file[y]=fopen(e,"rb");
fread(&x[y],sizeof(int),1,file[y]);
}
//for(y=0;y<=9;y++) fseek(file[y],0,SEEK_SET);
int i=0;
int loopRun=size*10;
while(i<loopRun)
{
smallest=x[0];
for(y=1;y<=9;y++) 
{
if(smallest>x[y])
{
smallest=x[y];
index=y;
}
}
if(smallest==x[0]) index=0;
fwrite(&smallest,sizeof(int),1,f);
pos=ftell(file[index]);
fseek(file[index],pos,SEEK_SET);
fread(&x[index],sizeof(int),1,file[index]);
i++;
}
fclose(f);
for(y=0;y<=9;y++)fclose(file[y]);
}

void sortIt(int *x,int lb,int ub)
{
int e,f,g;
for(e=lb;e<ub-1;e++)
{
for(f=e+1;f<ub;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
}

int main()
{
int y,noOfNumbers,b;
FILE *f;
FILE *file[10];
y=0;
f=fopen("File.d","wb");
for(y=0;y<1000;y++)
{
b=rand();
fwrite(&b,sizeof(int),1,f);
}
fclose(f);
f=fopen("File.d","rb");
fseek(f,0,SEEK_END);
int pos=ftell(f);
fseek(f,0,SEEK_SET);
noOfNumbers=pos/sizeof(int);
int size=noOfNumbers/10;
printf("The number of elements per file is : %d\n",size);
int arr[size];
y=0;
char e[15];
int noPos=0;
while(y<=9)
{
sprintf(e,"Files%d.data",y);
file[y]=fopen(e,"wb");
fseek(f,noPos,SEEK_SET);
fread(&arr,sizeof(int *),size,f);
sortIt(arr,0,size);
fwrite(&arr,sizeof(int *),size,file[y]);
y++;
noPos+=size;
}
fclose(f);
for(y=0;y<=9;y++) fclose(file[y]);
y=0;
int i;

sortAll(size);
FILE *newF;
newF=fopen("mainFile.d","rb");
for(i=0;i<10;i++)
{
fread(&arr,sizeof(int *),100,newF);
y=0;
while(y<100)
{
printf("%d, ",arr[y]);
y++;
}
}
fclose(newF);
for(y=0;y<=9;y++)
{
sprintf(e,"Files%d.data",y);
remove(e);
}

return 0;
}