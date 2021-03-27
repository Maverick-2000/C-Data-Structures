#include<stdio.h>
#include<stdlib.h>
int top=-1,max,stack[50];
void push (int element);
int pop (); 
void display ();

void push (int element)
{
if (top==max-1)
{
printf ("\n Stack Overflow \n");
}
else
{
top++;
stack[top]=element;
printf ("\n Element Pushed");
}
}

int pop ()
{
if (top==-1)
{
printf ("\n Stack Underflow \n");
}
else
{
int item;
item=stack[top];
top--;
return item;
}
}

void display ()
{
int i;
if (top==-1)
{
printf ("\n Stack Empty.");
}
else
{
for (i=top;i>=0;i--)
{
printf ("\n %d",stack[i]);
}
}
}

main ()
{
int c,e,p;
printf ("\n Enter Max Size: ");
scanf ("%d",&max);
do
{
printf ("\n");
printf ("\n 1. Push");
printf ("\n 2. Pop");
printf ("\n 3. Display");
printf ("\n 4. Exit");
printf ("\n Enter choice: ");
scanf ("%d",&c);
switch (c)
{
case 1 : printf ("\n Enter Element: ");
	 scanf ("%d",&e);
	 push(e);
	 
	 break;
case 2 : printf ("\n Calling pop function ... ");
	 p=pop();
	 printf ("\n Popped: %d",p);
	 
	 break;
case 3 : printf ("\n Calling display function...");
	 display ();
	 
	 break;
case 4 : exit (0);
	 break;
default : printf ("\n Choose another option");
}
}while (1);
}
