////////////////////////////////////////////////////////////////////////////////////////////////
//
//	41.Write a program which add new node in singly circular linked list at first position. 
//	Function Prototype : int InsertFirst( struct node **Head, struct node **Tail,  int no )
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node *next;
};
//////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		InsertFirst
//
//		Parameters	  :		1.struct Node **head => starting address of list.
//							2.struct Node **tail => ending address of list.
//							3.int no => data which we have to add.
//	
//		Description	  :		This function adds new element at the starting of list.
//
//		Returns		  :		int => 1 if function succeeds otherwise 0
//
//////////////////////////////////////////////////////////////////////////////////////
int InsertFirst(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	//allocate memory for new node
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode == NULL)
	{
		return 0;
	}

	newnode->data=no;
	newnode->next=NULL;

	if(*head == NULL)
	{
		*head=*tail=newnode;
		(*tail)->next=*head;
	}
	else
	{
		newnode->next=*head;
		*head=newnode;
		(*tail)->next=*head;
	}
	return 1;
}
//////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		DisplayList
//
//		Parameters	  :		1.struct Node *head => starting address of list.
//	
//		Description	  :		This function will display linked list.
//
//		Returns		  :		void
//
//////////////////////////////////////////////////////////////////////////////////////

void DisplayList(struct Node *head)
{
	struct Node *temp=head;

	if(head)
	{
		do
		{
			printf("|%d|->",temp->data);
			temp=temp->next;
		}while(temp!=head);	
	}
	else
	{
		printf("\n\n Linked list is empty.");
	}
}
int main()
{
	struct Node *first=NULL;
	struct Node *last=NULL;

	InsertFirst(&first,&last,10);
	InsertFirst(&first,&last,20);
	InsertFirst(&first,&last,30);
	InsertFirst(&first,&last,40);
	InsertFirst(&first,&last,50);

	printf("\n The linked list is => ");
	DisplayList(first);

	InsertFirst(&first,&last,21);
	printf("\n\n After adding node at first position , the linked list is  => \n");
	DisplayList(first);

	getch();
	return 0;
}
///////////////////////////////////////////////////////////////////////
//
//		Linked list	:	50 40 30 20 10
//
//		Input		:   21
//
//		Output	    :	21 50 40 30 20 10
//
////////////////////////////////////////////////////////////////////////