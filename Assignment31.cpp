///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		31.Write a program which accept source and destination linked list from user and we have to insert source 
//		   linked list in destination linked list at given position. 
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

 /////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertAt
 //
 //		Parameters		:	1. struct Node *Src   => Holds address of source list.
 //							2. struct Node **Dest => Holds address of dest list
 //							2. int pos			  => Holds position at which list is to be insert.
 //
 //		Description     :	This function inserts source list in the dest.list at specific
 //							position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 ///////////////////////////////////////////////////////////////////////////////////////////////////
 
 int InsertAt( struct Node *Src , struct Node **Dest , int pos)
 {
	 struct Node *temp1=*Dest;
	 struct Node *temp2=Src;

	 if(Src == NULL || *Dest == NULL)
	 {
		return -1;
	 }

	 while(pos-2 && temp1->next!=NULL)
	 {
		temp1=temp1->next;
		pos--;
	 }
	 while(temp2->next!=NULL)
	 {
		temp2=temp2->next;
	 }
	 temp2->next=temp1->next;
	 temp1->next=Src;

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
	struct Node *second=NULL;

	//call the function to add node at first position.
	InsertLast(&first,1);
	InsertLast(&first,2);
	InsertLast(&first,3);
	InsertLast(&first,4);
	
	printf("\n\n Source linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);

	InsertLast(&second,10);
	InsertLast(&second,20);
	InsertLast(&second,30);
	InsertLast(&second,40);
	InsertLast(&second,50);
	InsertLast(&second,60);

	printf("\n\n Destination linked list is => ");

	DisplayList(second);

	InsertAt(first,&second,3);
	printf("\n\n After inserting source list into dest list => ");
	DisplayList(second);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :	1 2 3 4  
 //
 //		Dest   Linked List :	10 20 30 40 50 60
 //
 //		Output			  :		10 20 1 2 3 4 30 40 50 60
 //
 /////////////////////////////////////////////////////////////////////////////////////////////