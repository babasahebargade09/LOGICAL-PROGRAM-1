////////////////////////////////////////////////////////////////////////////////////////////////
//
//	42.Write a program which add new node in singly circular linked list at last position. 
//	Function Prototype :  int InsertLast( struct node **Head, struct node **Tail,  int no ); 
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
//		Function name :		InsertLast
//
//		Parameters	  :		1.struct Node **head => starting address of list.
//							2.struct Node **tail => ending address of list.
//							3.int no => data which we have to add.
//	
//		Description	  :		This function adds new element at the end of list.
//
//		Returns		  :		int => 1 if function succeeds otherwise 0
//
//////////////////////////////////////////////////////////////////////////////////////
int InsertLast(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	//allocate memory for new node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory for newnode is allocate or not.
	if(newnode == NULL)
	{
		return 0;
	}

	//fill node with data.
	newnode->data=no;
	newnode->next=NULL;

	//if linked list is empty.
	if(*head == NULL)
	{
		*head=*tail=newnode;
		(*tail)->next=*head;
	}
	//if linked list contains at least one node.
	else
	{
		(*tail)->next=newnode;
		newnode->next=*head;
		*tail=newnode;
		
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

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);

	printf("\n The linked list is => \n");
	DisplayList(first);

	InsertLast(&first,&last,21);
	printf("\n After adding node at the last position , linked list is => \n");
	DisplayList(first);

	getch();
	return 0;
}
///////////////////////////////////////////////////////////////////////
//
//		Linked list		:	10 20 30 40 50
//
//		Input			:	21
//
//		Output			:	10 20 30 40 50 21
//
////////////////////////////////////////////////////////////////////////