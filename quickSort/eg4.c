#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}



typedef struct __Stack_Node
{
int data;
struct __Stack_Node *next;
}StackNode;

typedef struct __Stack
{
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack)
{
stack->top=NULL;

stack->size=0;
}

void push(Stack *stack,int num)
{
StackNode*t;
t=(StackNode*)malloc(sizeof(StackNode));
t->data=num;
t->next=stack->top;
stack->top=t;
stack->size++;
}

int pop(Stack* stack)
{
StackNode *t;
int data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
free(t);
stack->size--;
return data;
}

int isEmpty(Stack *stack)
{
return stack->top==NULL;
}

int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}

void quickSort(int *x,int lowerBound,int upperBound)
{
Stack lbStack,ubStack;
int pp,lb,ub;
initStack(&lbStack);
initStack(&ubStack);
push(&lbStack,lowerBound);
push(&ubStack,upperBound);
while(!isEmpty(&lbStack))
{
lb=pop(&lbStack);
ub=pop(&ubStack);

pp=findPartitionPoint(x,lb,ub);

if(pp+1<ub)
{
push(&lbStack,pp+1);
push(&ubStack,ub);
}
if(pp-1>lb)
{
push(&lbStack,lb);
push(&ubStack,pp-1);
}
}
}

int main()
{
int y=0,req;
int *x;
printf("Enter your requirement : ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
if(x==NULL) printf("Unable to allocate memory : \n");
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}

quickSort(x,0,req-1);
printf("\nAnd this is your Sorted array : \n");
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}