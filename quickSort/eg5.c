#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct __stack_Node
{
void *data;
struct __stack_Node *next;
}StackNode;

typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;

void init(Stack*stack,int es)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=es;
}

void push(Stack *stack,void *data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=(void *)malloc(stack->elementSize);
memcpy(t->data,(const void *)data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}

void pop(Stack*stack,void *data)
{
StackNode*t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void*)t->data,stack->elementSize);
free(t->data);
free(t);
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}

int findPartitionPoint(void*x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
e=lb;
f=ub;
void*g;
g=(void *)malloc(es);
while(e<f)
{
while(e<ub && p2f((x+(e*es)),(x+(lb*es)))<=0) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,(const void*)x+(e*es),es);
memcpy(x+(e*es),(const void*)x+(f*es),es);
memcpy(x+(f*es),(const void*)g,es);
}
else
{
memcpy(g,(const void*)x+(f*es),es);
memcpy(x+(f*es),(const void*)x+(lb*es),es);
memcpy(x+(lb*es),(const void*)g,es);
}
}
return f;
}

void quickSort(void *x,int lb,int ub,int es,int (*p2f)(void*,void*))
{
typedef struct __LBUB
{
int lb,ub;
}LBUB;
Stack stk;
int pp;
LBUB lbub;
init(&stk,sizeof(LBUB)); 
lbub.lb=lb;
lbub.ub=ub;
push(&stk,(void *)&lbub);
while(!isEmpty(&stk))
{
pop(&stk,(void *)&lbub);
lb=lbub.lb;
ub=lbub.ub;
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub)
{
lbub.lb=pp+1;
lbub.ub=ub;
push(&stk,(void*)&lbub);
}
if(pp-1>lb)
{
lbub.lb=lb;
lbub.ub=pp-1;
push(&stk,(void*)&lbub);
}
}
}

int myComparator(void*left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}


int main()
{

int x[10];
int y=0;
for(;y<=9;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}

quickSort((void*)x,0,9,sizeof(int),myComparator);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}


return 0;
}
