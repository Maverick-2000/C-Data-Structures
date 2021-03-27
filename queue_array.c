#include<stdio.h>
#include<stdlib.h>
int front,rear,a[50],max;
front=-1;
rear=-1;
void enq (int e);
int deq ();
void displ();
int main()
{
int c,ele,r;
printf ("\n Enter Max Size: ");
scanf ("%d",&max);
while (1)
{
printf ("\n");
printf ("\n 1. Enqueue");
printf ("\n 2. Dequeue");
printf ("\n 3. Display");
printf ("\n 4. Exit");
printf ("\n Enter Choice: ");
scanf ("%d",&c);
switch (c)
{
case 1 : printf ("\n Enter element: ");
	 scanf ("%d",&ele);
	 enq(ele);
	 break;
case 2 : r=deq();
	 printf ("\n Element Popped: %d ",r);
	 break;
case 3 : displ();
	 break;
case 4 : exit (0);
	 break;
default: printf ("\n Wrong Input");
}
}
return 0;
}
void enq (int e)
{
if (rear==max-1)
{
printf ("\n Overflow");
}
else if (front==-1 && rear==-1)
{
front++;
rear++;
a[rear]=e;
printf ("\n Element Pushed");
}
else
{
rear++;
a[rear]=e;
printf ("\n Element Pushed");
}
}
int deq ()
{
int item;
if (front==-1 && rear==-1)
{
printf ("\n Underflow");
}
else if (front == rear )
{
front=-1;
rear=-1;
}
else
{
item=a[front];
front++;
return item;
}
}
void displ ()
{
if (front==-1 && rear==-1 )
{
printf ("\n Queue is empty");
}
else
{
int i;
printf ("\n Displaying ...");
for (i=front;i<=rear;i++)
{
printf ("\n %d",a[i]);
}
}
}

