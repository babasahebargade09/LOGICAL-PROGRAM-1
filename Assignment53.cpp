////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	53.Write a program which accept two singly circular linked list from user and concat first N elements 
//	of source linked list after destination linked list. 
//	Function Prototype :  int ConcatFirstN(  struct node **SrcHead , struct node **SrcTail,  
//  struct node **DestHead, struct node **DestTail, int no ); 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertLast 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at last position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	ConcatFirstN
//
//		Description		:	This function concat first N elements of source list after 
//							destination linked list.
//
//		Returns			:  1 on success otherwise return 0
//
//////////////////////////////////////////////////////////////////////////////////////////////
int ConcatFirstN(struct Node **SrcHead,struct Node **SrcTail,struct Node **DestHead,struct Node **DestTail,int no)
{
	struct Node *newnode=NULL;
	struct Node *temp=*SrcHead;

	if(*SrcHead == NULL || *DestHead == NULL)
	{
		return 0;
	}

	do
	{
		newnode=(struct Node *)malloc(sizeof(struct Node));
		if(newnode == NULL)
		{
			return 0;
		}
	
		newnode->next=newnode;
		newnode->data=temp->data;

		(*DestTail)->next=newnode;
		*DestTail=newnode;
		(*DestTail)->next=*DestHead;
	
		temp=temp->next;
		no--;
	}while( no!=0 && temp!=*SrcHead);


	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	Display 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
 // 
 //		Description    :	This function displays linked list. 
 // 
 //		Returns		   :	void 
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
void Display(struct Node *head)
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
	Display(first1);


	InsertLast(&first2,&last2,11);
	InsertLast(&first2,&last2,22);
	InsertLast(&first2,&last2,33);
	InsertLast(&first2,&last2,44);
	InsertLast(&first2,&last2,55);

	printf("\n\n The second linked list is => ");
	Display(first2);

	ConcatFirstN(&first1,&last1,&first2,&last2,3);
	printf("\n\n After concatination of two lists the linked list is => ");
	Display(first2);

	getch();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//
//		Source Linked list	:	10 20 30 40 50
//
//		Dest Linked list	:	11 22 33 44 55
//
//		Output				:	11 22 33 44 55 10 20 30
//////////////////////////////////////////////////////////////////////////////////////////////

