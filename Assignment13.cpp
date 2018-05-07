//////////////////////////////////////////////////////////////////////////////////////
//
//	13.Write a program which accept two singly linear linked list from user and 
//	   concat first N elements of source linked list after destination linked list.
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
 //		Function Name   :	ConcatFirstN 
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will concate first N nodes of source list to destination list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int ConcatFirstN(  struct Node **Src , struct Node **Dest ,int no )
 {
	struct Node *temp1=*Dest;
	struct Node *temp2=*Src;

	//If any one of the linked list is empty.
	if(*Src==NULL || *Dest==NULL )
	{
		return -1;
	}
	

	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	//assigning addres of source list to the last node of dest list.
	temp1->next=*Src;

	while(temp1->next!=NULL && no!=0)
	{
		temp1=temp1->next;
		no--;
	}
	if(temp1->next!=NULL)
	{
		temp2=temp1->next;
		temp1->next=NULL;

		temp1=temp2->next;
		while(temp1!=NULL)
		{
			free(temp2);
			temp2=temp1;
			temp1=temp1->next;
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
	struct Node *second=NULL;

	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);

	InsertLast(&second,15);
	InsertLast(&second,25);
	InsertLast(&second,35);
	InsertLast(&second,45);
	InsertLast(&second,55);
	
	printf("\n\n First Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Second Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	//This function will concate two singly lineat linked list.
	ConcatFirstN(&first,&second,3);

	printf("\n\n After concatination of two linked list => ");
	DisplayList(second);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		1 => 10 20 30 40 50.  2=> 15 25 35 45 55  no=3
 //
 //		Output			  :		15 25 35 45 55 10 20 30  
 //
 /////////////////////////////////////////////////////////////////////////////////////////////