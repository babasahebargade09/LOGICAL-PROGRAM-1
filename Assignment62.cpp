///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		62.Write a program which add new node in doubly linear linked list at specified position.
//		Function Prototype :  int InsertAtPosition( struct node **Head,  int no, int pos );
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
	Node *prev; //holds address of previous node in the linked list.
};


 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertLast 
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. struct Node **tail => Holds last pointer of list
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at last position in doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int InsertLast( struct Node **head , struct Node **tail ,  int no )
 {
	struct Node *newnode=NULL;
	
	//allocate memory for node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory is allocated or not.
	if(newnode == NULL)
	{
		return 0;
	}

	//fill node with the data.
	newnode->next=newnode->prev=NULL;
	newnode->data=no;

	//Add node at first position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=*tail=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		(*tail)->next=newnode;
		newnode->prev=*tail;
		*tail=newnode;
	}
	return 1;
 }
  //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertFirst 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at first position in doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
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
		return 0;
	}

	//fill node with the data.
	newnode->next=newnode->prev=NULL;
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
		(*head)->prev=newnode;
		*head=newnode;
	}
 }




int Count(struct Node *head)
{
	int count=0;

	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertAtPosition
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //							3. int pos			  => position at which we have to add node.
 //
 //		Description     :	This function inserts node at specific position in doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int InsertAtPosition( struct Node **head ,struct Node **tail, int no , int pos )
 {
	struct Node *newnode=NULL;
	struct Node *temp=NULL;

	// If linked list is empty
	if( *head == NULL )
	{ 
		return  0;
	}
	
	else if( pos == 1 )
	{
		InsertFirst( head,no ); 
	}
	else if(pos == (Count( *head )) + 1)
	{
		InsertLast( head,tail,no ); 
	}
	else if( (pos > (Count(*head))+1))
	{
		return  0;
	}
	else
	{
		temp = *head ;
		newnode = (struct Node *)malloc(sizeof(struct Node ));
		if (NULL == newnode)
		{
			return  0;
		}

		//
		//	Fill the node with data.
		//
		newnode -> next = newnode->prev = NULL;
		newnode -> data = no;
	
		while(pos - 2 != 0 && temp!=NULL )
		{
			temp = temp -> next;
			pos--;
		}
		newnode-> next = temp -> next;
		temp->next->prev = newnode;
		temp -> next = newnode;
		newnode->prev = temp;
	}

	return  1;
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
	struct Node *last=NULL;

	//call the function to add node at last position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);

	printf("\n\n The linked list is =>");

	DisplayList(first);

	printf("\n\n After inserting element at the last position in the linked list => ");
	InsertAtPosition(&first,&last,21,4);
	InsertAtPosition(&first,&last,11,1);
	InsertAtPosition(&first,&last,51,8);
	InsertAtPosition(&first,&last,71,15);

	
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input	:	10 20 30 40 50 
 //
 //		Output	:   11 10 20 30 21 40 50 51
 //
 /////////////////////////////////////////////////////////////////////////////////////////////