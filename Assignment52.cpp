//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	52.Write a program which accept two singly circular linked list from user and concat source linked
//	list after destination linked list. 
//	Function Prototype :  int ConcatList(  struct node **SrcHead ,struct node **SrcTail, 
//	struct node **DestHead, struct node **DestTail ); 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};


int InsertLast(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	newnode=(struct Node *)malloc(sizeof(struct Node));

	if(newnode == NULL)
	{
		return 0;
	}
	
	newnode->data=no;
	newnode->next=newnode;

	if(*head == NULL)
	{
		*head=*tail=newnode;
		newnode->next=*head;
	}
	else
	{
		(*tail)->next=newnode;
		newnode->next=*head;
		*tail=newnode;
	}
	return 1;
}

int ConcatList( struct Node **SrcHead , struct Node **SrcTail , struct Node **DestHead, struct Node **DestTail )
{
	if(*SrcHead == NULL || *DestHead == NULL)
	{
		return 0;
	}

	(*SrcTail)->next=*DestHead;

	(*DestTail)->next=*SrcHead;

	return 1;
}

void DisplayList(struct Node *head)
{
	struct Node *temp=head;

	if(temp == NULL)
	{
		return;
	}

	do
	{
		printf("|%d|->",temp->data);
		temp=temp->next;

	}while(temp!=head);
}
int main()
{

	struct Node *first1=NULL;
	struct Node *last1=NULL;

	struct Node *first2=NULL;
	struct Node *last2=NULL;

	InsertLast(&first1,&last1,10);
	InsertLast(&first1,&last1,20);
	InsertLast(&first1,&last1,30);
	InsertLast(&first1,&last1,40);
	InsertLast(&first1,&last1,50);

	printf("\n\n The first linked list is => ");
	DisplayList(first1);


	InsertLast(&first2,&last2,11);
	InsertLast(&first2,&last2,22);
	InsertLast(&first2,&last2,33);
	InsertLast(&first2,&last2,44);
	InsertLast(&first2,&last2,55);

	printf("\n\n The second linked list is => ");
	DisplayList(first2);

	ConcatList(&first1,&last1,&first2,&last2);
	printf("\n\n After concatination of two lists the linked list is => ");
	DisplayList(first1);

	getch();
	return 0;
}

