///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	 3. Write a program which add new node in singly linear linked list at specified position. 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
};

 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertFirst 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at first position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int InsertFirst( struct Node **head,  int no )
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

	//Add node at first position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		newnode->next=*head;
		*head=newnode;
	}
	return 1;
 }

 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertLast 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at last position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////
int InsertLast( struct Node **head,  int no )
 {
	struct Node *newnode=NULL;
	struct Node *temp=NULL;

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
		*head=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		temp=*head;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return 1;
 }

 ///////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Function Name   :	Count
 //
 //		Parameters		:	1.struct Node *head   => Holds head pointer of list.
 //
 //		Description		:	This function returns number of nodes in the linked list.
 //
 //     Returns			:   int => Number of nodes in the linked list.  
 //
 ////////////////////////////////////////////////////////////////////////////////////////////

 int Count(struct Node *head)
 {
	int count=0;

	if(head)
	{
		while(head)
		{
			head=head->next;
			count++;
		}
	}
	else
	{
		return 0;
	}
	return count;
 }
 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertAtPosition 
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //							3. int pos			  => Position to add node.
 //
 //		Description     :	This function inserts node at specific position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int InsertAtPosition( struct Node **head,  int no, int pos )
 {
	struct Node *newnode=NULL;
	static struct Node *temp=NULL;
	int i;

	if(*head == NULL)
	{
		return -1;
	}
	else if( pos == 1 )
	{
		InsertFirst(head , no); 
	}
	else if(pos == (Count(*head)) + 1)
	{
		InsertLast(head , no); 
	}
	else if( (pos > Count(*head)))
	{
		return -1;
	}
	else
	{
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

		for( i=1,temp=*head; i<(pos-1) && temp->next!=NULL; i++,temp=temp->next);
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
		
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
	if(head)
	{
		while(head)
		{
			printf("|%d|->",head->data);
			head=head->next;
		}
	}
	else
	{
		printf("\n Linked list is empty.");
	}
 }
 
 
 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;

	//call the function to add node at last position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);

	printf("\n\n The linked list is => ");
	DisplayList(first);
	//call the function to add node at specific position.
	InsertAtPosition(&first,15,2);
	
	//This node will add at the first position in our linked list.
	InsertAtPosition(&first,5,1);

	InsertAtPosition(&first,45,6);
	
	//This node will add at the end of our linke list.
	InsertAtPosition(&first,60,9);

	//This node will not be add in our linked list, because position is greater than number of nodes in the linked list.
	InsertAtPosition(&first,65,22);
	
	printf("\n After adding nodes at the specific position , linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 
 //
 //		Input Data		  :		data(pos) => 15(2) 5(1) 45(6) 60(9) 65(22)
 //
 //		Output			  :		5 10 15 20 30 45 40 50 60
 //
 /////////////////////////////////////////////////////////////////////////////////////////////