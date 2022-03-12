#include<stdio.h>
#include<stdlib.h>

typedef struct __node__
{
int num;
struct __node__ *next;
}Node;

typedef struct __sll__
{
Node *start;
int size;
}SinglyLinkedList;

void initializeSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
singlyLinkedList->start=NULL;
singlyLinkedList->size=0;
}

void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int num)
{
Node *t,*p1,*p2;
t=(Node*)malloc(sizeof(Node));
t->num=num;
t->next=NULL;
if(singlyLinkedList->start==NULL)
{
singlyLinkedList->start=t;
}
else
{
p1=singlyLinkedList->start;
while(p1!=NULL)
{
if(p1->num>num)break;
p2=p1;
p1=p1->next;
}
if(p1==singlyLinkedList->start)
{
t->next=singlyLinkedList->start;
singlyLinkedList->start=t;
return;
}
if(p1==NULL)
{
p2->next=t;
return;
}
t->next=p1;
p2->next=t;
}

}

int isEmpty(SinglyLinkedList *singlyLinkedList)
{
return singlyLinkedList->start==NULL;
}

int keyMaker(int num)
{
int dc=1;
while(num>9)
{
num=num/10;
dc++;
}
return dc;
}

int removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
Node *t;
int data;
t=singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
data=t->num;
free(t);
return data;
}

int main()
{
int y,x[10],i,key;
SinglyLinkedList *singlyLinkedList[10];
y=0;
while(y<10)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
for(y=0;y<10;y++) singlyLinkedList[y]=(SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
for(y=0;y<10;y++) initializeSinglyLinkedList(singlyLinkedList[y]);
for(y=0;y<10;y++) 
{
key=keyMaker(x[y]);
insertIntoSinglyLinkedList(singlyLinkedList[key],x[y]);
}

int j=0;
y=0;
while(y<10)
{
while(!isEmpty(singlyLinkedList[y]))
{
i=removeFromSinglyLinkedList(singlyLinkedList[y]);
x[j]=i;
j++;
}
y++;
}

for(y=0;y<10;y++) printf("%d\n",x[y]);

return 0;
}
