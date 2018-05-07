////////////////////////////////////////////////////////////////////////////////////////
//
//	44.Write a program which remove last node from singly circular linked list. 
//	Function Prototype :  int DeleteLast(  struct node **Head, struct node **Tail);
//
////////////////////////////////////////////////////////////////////////////////////////
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
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

 int InsertLast( struct Node **head,struct Node **tail,  int no )
 {
	struct Node *newnode=NULL;

	//allocate memory for node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory is allocated or not.
	if(newnode == NULL)
	{
		return -1;
	}

	//fill node with the data.
	newnode->next=NULL;
	newnode->data=no;

	//Add node at last position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=*tail=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		(*tail)->next=newnode;
		*tail=newnode;
		(*tail)->next=*head;
	}
	return 1;
 }
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Function Name	:	 DeleteLast
 //
 //		Parameters		:	1.struct Node **head => holds starting address of the list.
 //							2.struct Node **tail => holds ending address of the list.
 //
 //		Description		:	This function deletes last node of the linked list.
 //
 //		Returns			:	int => on success returns 1 otherwise returns 0
 //
 //////////////////////////////////////////////////////////////////////////////////////////////

 int DeleteLast(struct Node **head , struct Node **tail)
 {
	struct Node *temp=*head;

	if(*head == NULL)
	{
		return 0;
	}
	else
	{
		while(temp->next!=*tail)
		{
			temp=temp->next;
		}
		temp->next=(*tail)->next;
		free(*tail);
		*tail=temp;
	}
	return 1;
	
 }

 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	DisplayList 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
 // 
 //		Description    :	This function displays linked list. 
 // 
 //		Returns		   :	void 
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 
void DisplayList(struct Node *head)
{
	struct Node *temp=head;

	if(temp)
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
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;
	struct Node *last=NULL;

	//call the function to add node at first position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);

	DeleteLast(&first,&last);
		
	printf("\n After deleting first node the linked list is => ");
	DisplayList(first);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 
 //
 //		Output			  :	    10 20 30 40  
 //
 /////////////////////////////////////////////////////////////////////////////////////////////