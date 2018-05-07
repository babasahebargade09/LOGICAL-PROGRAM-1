////////////////////////////////////////////////////////////////////////////////////////////////
//
//		35.Write a program which accept singly linear linked list from user and sort 
//		that linked list in descending order. 
//		Function Prototype :  int ListSortDec( struct Node **head );  
//
////////////////////////////////////////////////////////////////////////////////////////////////
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

 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	ListSortDec 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //
 //		Description     :	This function sort the list in descending order.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int ListSortDec(struct Node **head)
 {
	struct Node *temp1=*head;
	struct Node *temp2=(*head)->next;
	struct Node *temp3=NULL;

	if(*head == NULL || (*head)->next == NULL)
	{
		return -1;
	}
	
	while(temp2)
	{
		if(temp1->data < temp2->data)
		{
			if(temp1==*head && temp2==temp1->next)
			{
				temp1->next=temp2->next;
				temp2->next=*head;
				*head=temp2;
			}
			else 
			{
				temp3=*head;
				while(temp3->next!=temp1)
				{
					temp3=temp3->next;
				}
				temp3->next=temp2;
				temp1->next=temp2->next;
				temp2->next=temp1;
			}
			temp1=*head;
			temp2=temp1->next;
		}
		else
		{
			temp1=temp1->next;
			temp2=temp1->next;
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
	InsertLast(&first,30);
	InsertLast(&first,20);
	InsertLast(&first,10);
	InsertLast(&first,40);
	InsertLast(&first,60);
	InsertLast(&first,50);

	
	printf("\n\n Linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	//This function sorts list in descending order.
	ListSortDec(&first);

	//Display linked list after sorting.
	printf("\n\n After sorting the linked list is => ");
	DisplayList(first);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////
 //
 //		Input	:	30 20 10 40 60 50
 //
 //		Output  :   60 50 40 30 20 10
 //
 /////////////////////////////////////////////////////////////////////////////////