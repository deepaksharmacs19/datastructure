#include<stdio.h>


int partition(int *arr,int low,int high)
{
int pivot=arr[high];
int i=low-1;
int j=0;
int g;
for(j=low;j<=high-1;j++)
{
if(arr[j]<pivot)
{
i++;
g=arr[i];
arr[i]=arr[j];
arr[j]=g;
}
}
g=arr[high];
arr[high]=arr[i+1];
arr[i+1]=g;
return i+1;
}
void quicksort(int *arr,int low,int high)
{
int pi=0;
if(low<high)
{
pi=partition(arr,low,high);
quicksort(arr,low,pi-1);
quicksort(arr,pi+1,high);
}
}

int OrderStatistics(int *arr,int low,int high,int i)
{
quicksort(arr,low,high);
if(low<=i && high>=i) return arr[i];
else return -1;
}


int main()
{
int arr[]={81,71,99,68,45,55,0,22,11,34};
int o=0;
o=OrderStatistics(arr,0,6,7);
int y=0;
printf("Required value is %d\n",o);
while(y<=9)
{
printf("%d\n",arr[y]);
y++;
}
return 0;
}