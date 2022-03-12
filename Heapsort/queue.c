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
return queue->size==0;
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

int main()
{

Queue *queue;
queue=(Queue*)malloc(sizeof(Queue));
initQueue(queue);

int num;
int ch;
while(1)
{
printf("1. Add to queue\n");
printf("2. Remove from queue \n");
printf("3. Exit\n");

printf("Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter number to add : ");
scanf("%d",&num);
addToQueue(queue,num);
printf("%d added to queue.\n",num);
}
else if(ch==2)
{
num=removeFromQueue(queue);
if(num==0) break; 
printf("%d removed from queue.\n",num);
}
else
{
break;
}
}

return 0;
}