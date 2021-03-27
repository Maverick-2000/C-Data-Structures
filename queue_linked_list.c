#include<stdio.h>
#include<stdlib.h>
// define list
struct node
{
int data;
struct node* next;
};

//global head
struct node*  front=NULL;
struct node*  rear=NULL;
//qinsert
void ins (int ele)
{ 
 struct node *new_node;
 //allocate new_node mem
 new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=ele;
 new_node->next=NULL;
 if (front==NULL)
 {
	front=rear=new_node;
 }
 else
  {
    rear->next=new_node;
    rear=new_node;
    
  }
}
//qdel
void qdel()
{
int ele;
if (front==NULL)
 {
	printf ("\n Underflow");
 }
 struct node *ptr;
 ptr=front;
 ele=ptr->data;
 if (front==rear)
  front=rear=NULL;
 else
  front=ptr->next;
 free(ptr);
printf ( "\n Element Deleted: %d",ele);
}
//disp
void display ()
{
 if (front ==NULL)
	printf ("\n Empty List");
 else
 {
struct node *temp;
   temp=front;
 while (temp!=NULL)
 {
  printf ("\n %d \n",temp->data);
  temp=temp->next;
 }
 }
}

void main ()
{
 int c,i;
 while (1)
 {
 	printf ("\n 1. Insert ");
	printf ("\n 2. Delete");
	printf ("\n 3. Display ");
	printf ("\n 4. Exit");
	printf ("\n Enter Choice: ");
	scanf ("%d",&c);
	switch (c)
	{
	  case 1: printf ("\n Enter Element: ");
		  scanf ("%d",&i);
 		  ins(i);
		  break;
	  case 2: qdel();
		  break;
	  case 3: display();
		  break;
	  case 4 : exit(0);
		  break;
 	  default: printf ("\n Wrong Choice !");  
	}
 }
}
