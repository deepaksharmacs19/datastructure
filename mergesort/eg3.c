#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int*)left;
leftInt=(int*)right;
return (*leftInt)-(*rightInt);
}

typedef struct __Stack__Node
{
void *data;
struct __Stack__Node *next;
}StackNode;

typedef struct __Stack
{
StackNode* top;
int elementSize;
int size;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}



void merge(void *x,int a,int mid,int b,int es,int (*p2f)(void *,void *))
{
int lb1,lb2,lb3,ub1,ub2,ub3;
lb1=a;
lb2=mid+1;
ub1=mid;
ub2=b;
ub3=(ub1-lb1)+(ub2-lb2);
printf("(%d)\n",ub3);
lb3=0;
void *tmp;
tmp=(void *)malloc(es*ub3);
while(lb1<=ub1 && lb2<=ub2)
{
if(p2f(x+(lb1*es),x+(lb2*es))<0)
{
memcpy((tmp+(lb3*es)),(const void *)(x+(lb1*es)),es);
lb1++;
}
else
{
memcpy((tmp+(lb3*es)),(const void *)(x+(lb2*es)),es);
lb2++;
}
lb3++;
}

while(lb1<=ub1)
{
memcpy((tmp+(lb3*es)),(const void *)(x+(lb1*es)),es);
lb1++;
lb3++;
}

while(lb2<=ub2)
{
memcpy((tmp+(lb3*es)),(const void *)(x+(lb2*es)),es);
lb2++;
lb3++;
}

lb3=0;
lb1=a;
while(lb1<=ub1)
{
memcpy((x+(lb1*es)),(const void *)(tmp+(lb3*es)),es);
lb3++;
lb1++;
}

lb2=mid+1;
while(lb2<=ub2)
{
memcpy(x+(lb2*es),(const void *)(tmp+(lb3*es)),es);
lb3++;
lb2++;
}

free(tmp);
}






int push(Stack *stack,void *data)
{
StackNode *node;
if(stack==NULL) return 0;
node=(StackNode*)malloc(sizeof(StackNode));
if(node==NULL) return 0;
if(data!=NULL)
{
node->data=(void *)malloc(stack->elementSize);
if(node->data==NULL)
{
free(node);
return 0;
}
memcpy(node->data,(const void *)data,stack->elementSize);
}
else
{
node->data=data;
}
node->next=stack->top;
stack->top=node;
stack->size++;
return 1;
}

int pop(Stack *stack,void *data)
{
int j;
StackNode *t;
if(stack==NULL) return 0;
if(stack->top==NULL) return 0;
memcpy(data,(const void *)stack->top->data,stack->elementSize);
t=stack->top;
stack->top=stack->top->next;
if(t->data!=NULL) free(t->data);
free(t);
stack->size--;
return 1;
} 

int isEmpty(Stack *stack)
{
if(stack->top==NULL) return 1;
if(stack->size==0) return 1;
return 0; 
}


void mergeSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int mid,a,b;
struct LBUB
{
int lb,ub;
};
Stack stack1,stack2;
initStack(&stack1,sizeof(struct LBUB));
initStack(&stack2,sizeof(struct LBUB));
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub);
while(!isEmpty(&stack1))
{
pop(&stack1,(void *)&lbub);

push(&stack2,(void *)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub);
}
if(b>mid+1)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub);
}
}

while(!isEmpty(&stack2))
{
pop(&stack2,(void *)&lbub);
//printf("%d, %d \n",lbub.lb,lbub.ub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;

merge(x,a,mid,b,es,p2f);

}
}


int main()
{

int x[10],y=0;

while(y<10)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}

mergeSort(x,0,9,sizeof(int),comparator);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}

return 0;
}