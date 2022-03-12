#include<stdio.h>
#include<stdlib.h>

typedef struct __queue_node
{
int num;
struct __queue_node *next;
}queueNode;

typedef struct __queue_
{
queueNode *start;
queueNode* end;
int size;
}Queue;

void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}

int isQueueEmpty(Queue *queue)
{
if(queue==NULL) return 1;
return queue->size==0 ;
}

void addToQueue(Queue *queue,int num)
{
queueNode *node;
node=(queueNode*)malloc(sizeof(queueNode));
node->num=num;
node->next=NULL;
if(queue->start==NULL)
{
queue->start=node;
queue->end=node;
}
else 
{
queue->end->next=node;
queue->end=node;
}
queue->size++;
}

int removeFromQueue(Queue *queue)
{
if(isQueueEmpty(queue))
{
printf("Queue is Empty.\n");
return 0;
}
queueNode *t;
int num;
t=(queueNode*)malloc(sizeof(queueNode));
t=queue->start;
queue->start=queue->start->next;
num=t->num;
free(t);
queue->size--;
return num;
}

void radixSort(int *x,int lb,int ub)
{
int e,f,num,dc,largest,k,i,y;

Queue queues[10];
for(y=0;y<=9;y++) initQueue(&queues[y]);
largest=x[lb];
for(y=lb+1;y<=ub;y++) 
{
if(largest<x[y]) largest=x[y];
}


dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}

k=1;
e=10;
f=1;
while(k<=dc)
{
y=lb;
while(y<=ub)
{
num=x[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
i=lb;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num;
i++;
}
y++;
}

e*=10;
f*=10;
k++;
}
}

int manageArray(int *x)
{
int f,e,pos=0;
int j,i;
f=0;
if(x[0]>0)
{
for(i=0;i<=9;i++)
{
if(x[i]<0)
{
e=x[f];
x[f]=x[i];
x[i]=e;
f++;
}
}
}
else
{
if(x[0]<0)
{
for(j=0;j<=9;j++)
{
if(x[j]>0) 
{
pos++;
break;
}
}
if(pos==0) return 10;
else
{
f=j;
i=j+1;
for(;i<=9;i++)
{
if(x[i]<0)
{
e=x[f];
x[f]=x[i];
x[i]=e;
f++;
}
}
}
}

}
return f;
}

void swapIt(int *x,int lb,int ub)
{
int e=0,f=ub;
int g;
for(;e<f;e++,f--)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}

int main()
{
int x[10],num,dc,largest,k,i;
int y,ub1,lb1;
for(y=0;y<=9;y++) 
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lb1=0;
ub1=manageArray(x);
for(int i=0;i<ub1;i++) x[i]*=(-1);
radixSort(x,0,ub1-1);
if(ub1<9) radixSort(x,ub1,9);
for(int i=0;i<ub1;i++) x[i]*=(-1);
swapIt(x,lb1,ub1-1);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}