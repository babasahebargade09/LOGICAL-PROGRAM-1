//////////////////////////////////////////////////////////////////////////////////////////////
//
//	8. Write a program which search first occurrence of particular element from 
//	
//	singly linear linked list. Function should return position at which element is found. 
//
//////////////////////////////////////////////////////////////////////////////////////////////

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
 } ///////////////////////////////////////////////////////////////////////////////////////////// 
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
 
 

////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	SearchFirstOcc
//
//		Parameters		:	1. struct node **head => Holds head pointer of list.
//							2. int no => Data of node to search first occ.
//
//		Description:	:	This function search perticular data in Singly Linear Linked List.
//							and return the position at which data is found.
//
//		Returns			:	int => Position at which data is found in list, 
//							otherwise return -1.
//
////////////////////////////////////////////////////////////////////////////////////////////////
 int SearchFirstOcc( struct Node *head , int no ) 
 {
	int pos=0;
	
	if(head)
	{
		while(head)
		{
			++pos;
			if(head->data == no)
			{
				return pos;
				break;
			}
			head=head->next;
		}
	}
	else
	{
		printf("\n\n Linked list is empty.");
	}
	return -1;
 }

 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;

	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
	InsertLast(&first,60);
	InsertLast(&first,70);

	printf("\n The linked list is =>");
	DisplayList(first);

	//This function searches the first occurrence of the node in the linked list.
	int pos=SearchFirstOcc(first,30); 
	
	if(pos!=-1)
	{
		printf("\n Element is found at %d position. ",pos);
	}
	else
	{
		printf("\n Element is not found in the linked list.");
	}

	pos=SearchFirstOcc(first,90); 
	if(pos!=-1)
	{
		printf("\n Element is fount at %d position. ",pos);
	}
	else
	{
		printf("\n Element is not found in the linked list.");
	}

	

 	getch();
	return 0;
 }

 //////////////////////////////////////////////////////////////////////////////////
 //
 //		Input1	:	List => 10 20 30 40 50  60  70 , no => 30
 //
 //		Output1	:	Element is found at 3 position.
 //
 //		Input2	:	List => 10 20 30 40 50  60  70 , no => 90
 //
 //		Output2	:	Element is not found in the linked list.
 //
 //////////////////////////////////////////////////////////////////////////////////
