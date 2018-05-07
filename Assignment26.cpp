///////////////////////////////////////////////////////////////////////////////////////////////////
//
//		26.Write a program which accept source singly linear linked list from user and copy 
//	
//		   the contents into destination singly linear linked in descending order.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

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
 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	CopyDsc
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will copy content of source list into the destination
 //							list in descending order.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int CopyDsc(struct Node *Src,struct Node **Dest)
 {
	struct Node *newnode=NULL;
	struct Node *temp1=NULL;
	struct Node *temp2=NULL;

	if(Src == NULL)
	{
		return 0;
	}
	while(Src!=NULL)
	{
		newnode=(struct Node *)malloc(sizeof(struct Node));

		if(newnode == NULL)
		{
			return 0;
		}

		newnode->data=Src->data;
		newnode->next=NULL;

		if(*Dest == NULL)
		{
			*Dest=newnode;
		}
		else if(newnode->data > (*Dest)->data)
		{
			newnode->next=*Dest;
			*Dest=newnode;
		}
		else if(newnode->data < (*Dest)->data)
		{	
			temp1=*Dest;
			while( temp1!=NULL && temp1->data > newnode->data  )
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			
			newnode->next=temp1;
			temp2->next=newnode;
		}
		Src=Src->next;
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
	struct Node *second=NULL;
	
	//call the function to add node at first position.
	InsertLast(&first,30);
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,70);
	InsertLast(&first,90);
	
	printf("\n The source Linked list is => ");
	DisplayList(first);

	CopyDsc(first,&second);
	printf("\n The destination linked list is =>");
	DisplayList(second);
	
	getch();
	return 0;
 }

 ////////////////////////////////////////////////////////////////////////////
 //
 //		Linked list	:	30 10 20 70 90
 //
 //		Output		:	90 70 30 20 10
 //
 ////////////////////////////////////////////////////////////////////////////
