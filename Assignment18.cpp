//////////////////////////////////////////////////////////////////////////////////////
//
//	18.Write a program which copies last N contents of source singly linear linked 
//     list to destination singly linear linked list.
//
//////////////////////////////////////////////////////////////////////////////////////

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
 //		Function Name   :	LLINCopy
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //							3. int no => Number of nodes to copy.		
 //
 //		Description     :	This function will copy last N elements of source list into destination list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int LLINCopy(  struct Node *Src , struct Node **Dest ,int no)
 {
	struct Node *temp1=*Dest;
	struct Node *newnode=NULL;
	struct Node *temp2=Src;

	//If any one of the linked list is empty.
	if(Src == NULL || no<=0)
	{
		return -1;
	}

	//Following two loops are used to reach at the specific position from end of list.
	while(temp2!=NULL && no!=0)
	{
		temp2=temp2->next;
		no--;
	}
	while(temp2!=NULL)
	{
		Src=Src->next;
		temp2=temp2->next;
	}

	//Following loop is used to copy content from src list to dest list.
	while(Src!=NULL)
	{
		//Allocate memory for node.
		newnode=(struct Node *)malloc(sizeof(struct Node));

		//check whether memory is allocated or not.
		if(newnode == NULL)
		{
			return -1;
		}

		//Assigning data
		newnode->next=NULL;
		newnode->data=Src->data;

		//Add node in the linked list
		if(*Dest == NULL)
		{
			*Dest=temp1=newnode;
		}
		else
		{
			temp1->next=newnode;
			temp1=newnode;
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
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);

	
	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	
	//This function will concate two singly lineat linked list.
	LLINCopy(first,&second,3);

	printf("\n\n After copying content dest. linked list is=> ");
	DisplayList(second);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :	10 20 30 40 50
 //
 //		Dest linked list   :	Empty(NULL)list.
 //
 //		Output(Dest list)  :	30 40 50   
 //
 /////////////////////////////////////////////////////////////////////////////////////////////