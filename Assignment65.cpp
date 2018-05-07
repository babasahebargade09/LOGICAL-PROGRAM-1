//////////////////////////////////////////////////////////////////////////////////////////////
// 
//	65.Write a program which remove node from doubly linear linked list which is at 
//  specified position. Function Prototype:int DeleteAtPosition(struct node **Head,int pos ); 
//
//////////////////////////////////////////////////////////////////////////////////////////////

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
 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	DeleteLast 
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. struct Node **tail -> holds last pointer of list.
 //
 //		Description     :	This function delete last node of doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int DeleteLast(struct Node **head,struct Node **tail)
 {
	struct Node *temp=*head;

	if(*head == NULL)
	{
		return 0;
	}
	else if((*head)->next == NULL ) // else if( *head == *tail) -> there is only one node in the list.
	{
		free(temp);
		*head=*tail=NULL;
	}
	else
	{
		while(temp->next!=*tail)
		{
			temp=temp->next;
		}

		temp->next=NULL;
		*tail=temp;
	}
	return 1;

 }

 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	DeleteFirst
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //
 //		Description     :	This function delete first node of doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////
  int DeleteFirst(struct Node **head)
 {
	struct Node *temp=*head;

	if(*head == NULL)
	{
		return 0;
	}
	else if((*head)->next == NULL ) // else if( *head == *tail) -> there is only one node in the list.
	{
		free(temp);
		*head=NULL;
	}
	else
	{
		*head=(*head)->next;
		(*head)->prev=NULL;
		free(temp);
	}
	return 1;

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
 //		Function Name   :	DeleteAtPosition 
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. struct Node **tail -> holds last pointer of list.
 //							3. int pos -> position to delete node.
 //
 //		Description     :	This function delete specific node of doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

int DeleteAtPosition(
						struct Node **head,
						struct Node **tail,
						int pos
					)
{
	if(pos > (Count(*head)))
	{
		return 0;
	}
	else if(pos == 1)
	{
		DeleteFirst(head);
	}
	else if(pos == (Count(*head)))
	{
		DeleteLast(head,tail);
	}
	else
	{
		struct Node *temp1 = *head,*temp2;

		while(pos-2!=0 )
		{
			temp1=temp1->next;
			pos--;
		}
		temp2=temp1->next;

		temp1->next=temp2->next;
		temp2->next->prev=temp1;
		free(temp2);

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
	 struct Node *first=NULL;
	 struct Node *last=NULL;

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,60);
 
	printf("\n\n The linked list is => ");
	DisplayList(first);

	//DeleteAtPosition(&first,&last,6);
	//DeleteAtPosition(&first,&last,1);
	DeleteAtPosition(&first,&last,3);
	//DeleteAtPosition(&first,&last,13);
	printf("\n\n The list is => ");
	DisplayList(first);

	getch();
	return 0;
 }

 ///////////////////////////////////////////////////////////////////////
 //
 //		Input	:	10 20 30 40 50 60
 //
 //		pos		:	3
 //
 //		Output	:	10 20 40 50 60
 //
 ////////////////////////////////////////////////////////////////////////