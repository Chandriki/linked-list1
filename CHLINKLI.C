#include<stdio.h>
#include<conio.h>
typedef struct lklist
{
int info;
struct lklist *next;
}node;
void main()
{
void traverse(node*);
void insert_at_end(node**,int);
void delete_at_end(node**);
void delete_at_beg(node**);
 node *head=NULL,*temp;
 int choice,item;
while(1){
 printf("\n1.Insert at begining");
 printf("\n2.Insert at end");
 printf("\n3.traverse");
 printf("\n4.Delete at end\n");
 printf("\n5.delete at begining");
 printf("\n6.for exit");
 printf("\nEnter your choice");
 scanf("%d",&choice);

 switch(choice){
 case 1:
 printf("enter the value to be insert");
 scanf("%d",&item);
 temp=(node*)malloc(sizeof(node));
 temp->info=item;
 if(head==NULL)
 {
 temp->next=NULL;
 }
 else{
 temp->next=head;
 }
 head=temp;
 break;
 case 2:
  printf("enter items:");
  scanf("%d",&item);
  insert_at_end(&head,item);
  break;
  case 3:
  if(head==NULL)
  {
  printf("list is empty");
  }
  else{
  traverse(head);
  }
  break;
  case 4:
  if(head==NULL)
  {
  printf("list is empty");
  }
  else
  {
  delete_at_end(&head);
  }
  break;
  case 5:
  if(head==NULL)
  {
  printf("list is empty");
  }
  else
  {
  delete_at_beg(&head);
  }
  break;
  case 6:exit(0);
  break;
  default:
  printf("wrong choice");
  break;
  }
  getch();
  }
  }
   void traverse(node *start)
   {
   while(start!=NULL)
   {
   printf("%d",start->next);
   start=start->next;
   }
   }
   void insert_at_end(node **start,int item)
   {
   node *temp,*loc;
   temp=(node*)malloc(sizeof(node));
   temp->info=item;
   temp->next=NULL;
   if(*start==NULL)
   {
   *start=temp;
   }
   else{
   loc=*start;
   }
   while(loc->next!=NULL)
   {
   loc=loc->next;
   }
   loc->next=temp;
   }
   void delete_at_end(node **start)
   {
   node *loc,*temp;
   loc= *start;
   if((*start)->next==NULL)
   {
   temp=*start;
   *start=NULL;
   }
   else
   {
   while(((loc->next)->next)!= NULL)
   {
   loc=loc->next;
   temp=loc->next;
   loc->next=NULL;
    }
   free(temp);
   }
    }
   void delete_at_beg(node **start)
   {
   node *temp;
   temp=*start;
   *start=(*start)->next;
   free(temp);
   }