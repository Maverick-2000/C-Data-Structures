#include<stdio.h>
#include<stdlib.h>
struct node 
{
int coeff;
int power;
struct node* next;
}*poly1=NULL,*poly2=NULL,*poly3=NULL,*ptr,*temp;

void createpoly (struct node *p)
{
 int c=1;
 while (c!=0)
 {
 printf ("\n Enter Co-Eff: ");
 scanf ("%d",&p->coeff);
 printf ("\n Enter Power: ");
 scanf ("%d",&p->power);
 p->next=(struct node*)malloc(sizeof(struct node)); 
 p=p->next;
 p->next=NULL;
 printf ("\n Continue (1/0): ");
 scanf ("%d",&c);
 }
}

void add (struct node* p1,struct node* p2,struct node* p)
{
 while (p1->next!=NULL && p2->next!=NULL)
 {
  if (p1->power>p2->power)
  {
   p->coeff=p1->coeff;
   p->power=p1->power;
   p1=p1->next;
  }
  else if (p1->power<p2->power)
   {
    p->coeff=p2->coeff;
    p->power=p2->power;
    p2=p2->next;
   }
  else
  {
   p->coeff=(p1->coeff)+(p2->coeff);
   p->power=p1->power;
   p1=p1->next;
   p2=p2->next;
  }
   p->next=(struct node*)malloc(sizeof(struct node)); 
   p=p->next;
   p->next=NULL;
 } 
while (p1->next!=NULL || p2->next!=NULL)
{
if (p1->next=NULL)
{
 p->coeff=p1->coeff;
 p->power=p1->power;
 p1=p1->next;
}
else
{
p->coeff=p2->coeff;
p->power=p2->power;
p2=p2->next;
}
 p->next=(struct node*)malloc(sizeof(struct node)); 
 p=p->next;
 p->next=NULL;
}
}
void display ()
{
 temp=poly3;
 while (temp->next!=NULL)
 {
  printf ("%dX^%d + ",temp->coeff,temp->power);
  temp=temp->next;
 }
 printf("\n");
}

int main()
{
printf ("\n Enter First Polynomial: ");
poly1=(struct node*)malloc(sizeof(struct node));
createpoly(poly1);
printf ("\n Enter Second Polynomial: ");
poly2=(struct node*)malloc(sizeof(struct node));
createpoly(poly2);
printf ("\n Result: ");
poly3=(struct node*)malloc(sizeof(struct node));
add(poly1,poly2,poly3);
display();
return 0;
}

