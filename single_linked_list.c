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

//create linked list
void create_list (int total)
{
int d,i;
struct node *new_node;
struct node *temp;
// input to head
head=(struct node*)malloc(sizeof(struct node));
printf ("\n Enter Data Node 1: ");
scanf ("%d",&d);
head->data=d;
head->next=NULL;
temp=head;
// enter the rest
for (i=1;i<total;i++)
{
//allocate new_node mem
new_node=(struct node*)malloc(sizeof(struct node));
printf ("\n Enter Data Node %d:",i+1);
scanf ("%d",&d);
new_node->data=d;
new_node->next=NULL;
temp->next=new_node;
temp=temp->next;
}
}

//display LL
void display_list(struct node * n)
{
if (head==NULL)
{
printf("\n Empty List");
}
else
{
printf ("\n Displaying list ... \n");
struct node* temp;
temp=n;
while (temp!=NULL)
{
printf("%d , ",temp->data);
temp=temp->next;
}
printf("\n");
}
}

//insert in front
void ins_beg(int d)
{
struct node* new_node;
//allocate mem
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=d;
new_node->next=head;
head=new_node;
}

//insert @ end
void ins_end(int d)
{
struct node* new_node;
struct node* temp;
//allocate mem
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=d;
new_node->next=NULL;
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new_node;
}

//insert @ pos
void ins_pos(int d,int pos)
{
int i;
struct node* new_node;
struct node* temp;
if (pos==1)
{
ins_beg(d);
}
else
{
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=d;
temp=head;
for (i=1;i<pos-1;i++)
{
temp=temp->next;
}
new_node->next=temp->next;
temp->next=new_node;
}
}

//del @ beg
void del_beg()
{
struct node* temp;
temp=head;
if (head==NULL)
{
printf ("\n Underflow");
}
else
{
head=temp->next;
free(temp);
}
}

//del @ end
void del_end()
{
struct node *temp;
struct node *secondl;
secondl=head;
temp=head;
if (head==NULL)
{
printf ("\n Underflow");
}
else if (temp->next==NULL)
{
head=NULL;
free(temp);
}
else
{
while (temp->next!=NULL)
{
secondl=temp;
temp=temp->next;
}
secondl->next=NULL;
free(temp);
}
}

//del @ pos
void del_pos(int pos)
{
int i;
struct node *temp;
struct node *secondl;
temp=head;
secondl=head;

if (head==NULL)
{
printf("\n Underflow");
}
else if (pos==1)
{
del_beg();
}
else
{
for (i=1;i<pos;i++)
{
secondl=temp;
temp=temp->next;
}
secondl->next=temp->next;
free(temp);
}
}

//del spec ele
void del_ele (int e)
{
struct node* temp;
struct node* prev;
temp=head;
if (head==NULL)
{
printf("\n Underflow");
}
else if (temp->data==e )
{
	if (temp->next==NULL)
	 head=NULL;
	else
	{
	  head=temp->next;
	  free (temp);
	}
}

else
{
	while (temp->next!=NULL)
	{
	  if (temp->data!=e )
	   {
	     prev=temp;
	     temp=temp->next;
	  }
	  else
	  {
	     prev->next=temp->next ;
	     free(temp);
	  }	
	}
}

}

int main()
{
int c,info,x,y,p,pdel,ele,t;
do
{
printf("\n 1. Create Linked List");
printf ("\n 2. Insert Data");
printf ("\n 3. Delete Data");
printf ("\n 4. Display List ");
printf ("\n 5. Exit");
printf ("\n Enter Choice: ");
scanf ("%d",&c);
switch (c)
{
case 1: printf("\n Enter Total Number of Elements: ");
	scanf ("%d",&t);
	create_list (t);
	break;
case 2: printf ("\n Enter Data: ");
	scanf ("%d",&info);
	printf ("\n 1. Insert in Front");
	printf ("\n 2. Insert at End");
	printf ("\n 3. Insert at specified position");
	printf ("\n Enter Choice: ");
	scanf ("%d",&x);
	if (x==1)
	  ins_beg(info);
	else if (x==2)
	  ins_end(info);
	else
	 {
		printf ("\n Enter Position: ");
	        scanf ("%d",&p);
		ins_pos(info,p);
	 }
	break;
case 3: printf ("\n 1. Delete in Front");
	printf ("\n 2. Delete End");
	printf ("\n 3. Delete a specified position");
	printf ("\n 4. Delete a specified element");
	printf ("\n Enter Choice: ");
	scanf ("%d",&y);
	if (y==1)
		del_beg();
	else if (y==2)
		del_end();
	else if (y==3)
	 {
		printf ("\n Enter Position: ");
	        scanf ("%d",&pdel);
		del_pos(pdel);
	 }
	else 
	{
		printf ("\n Enter Element to Delete: ");
	        scanf ("%d",&ele);
		del_ele (ele);	
	}
	break;

case 4 :display_list(head);
	break;

case 5 : exit(0);
	break;
default: printf ("\n Wrong Choice !");
}
}while (1);
return 0;
}


