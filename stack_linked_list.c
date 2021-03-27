#include<stdio.h>
#include<stdlib.h>
// define list
struct node
{
int data;
struct node* next;
};

//global head
struct node*  head=NULL;

void push (int ele) 
{
 struct node *new_node;
 //allocate new_node mem
 new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=ele;
 new_node->next=head;
 head=new_node;
}

void disp()
{
 if (head==NULL)
 { 
  printf ("\n Underflow");
 }
 else
 {
 struct node *temp;
 temp=head;
 while (temp!=NULL)
 {
 	printf ("\n %d \n",temp->data);
	temp=temp->next;
 }
 }
}
int pop()
{
 int del;
 if (head==NULL) //check underflow
 {
	return -1;
 }
 else
 {
 	struct node *temp;
 	temp=head;
	head=temp->next;
	del = temp->data;	
	free(temp);
	return del;
 }
}

int main ()
{
 int c,e,d;
 printf ("\n Stack implementation using Linked List");
 while (1)
 {
 	
	printf ("\n 1. PUSH");
	printf ("\n 2. POP");
	printf ("\n 3. DISPLAY");
	printf ("\n 4. EXIT");
	printf ("\n Enter Choice: ");
	scanf ("%d",&c);
 	switch (c)
	{
	  case 1: printf ("\n Enter Element: ");
		  scanf ("%d",&e);
		  push(e);
		  break;
	  case 2: d=pop();
  		  if (d==-1)
			printf ("\n Underflow");
		  else
	 	        printf ("\n Element Deleted: %d",d);
		  break;
	  case 3: disp();
		 break;
	  case 4: exit(1);
   		 break;
	  default: printf ("\n Wrong Choice !"); 	
	}
 }
 return 0;
}
