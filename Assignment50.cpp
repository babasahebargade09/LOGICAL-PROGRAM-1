////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	50.Write a program which search second last occurrence of particular element from singly 
//	circular linked list. Function should return position at which element is found. 
//	Function Prototype :  int SearchSecLastOcc(  struct node *Head,struct node *Tail,  int no ); 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	SearchLastOcc
//
//		Parameters		:	1. struct node **head => Holds head pointer of list.
//							2. int no => Data of node to search last occ.
//
//		Description:	:	This function search last occurrence of data in Singly Linear Linked List.
//							and return the position at which data is found.
//
//		Returns			:	int => Position at which data is found in list, 
//							otherwise return -1.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
 int SearchSecLastOcc( struct Node *head , struct Node *tail , int no ) 
 {
	struct Node *temp=head;
	 
	int pos1=0;
	int pos2=0;
	int pos3=0;
	
	if(head == NULL)
	{
		return 0;
	}
	do
	{
		++pos1;
		if(temp->data == no)
		{
			pos3=pos2;
			pos2=pos1;
		}
		temp=temp->next;
	}while(temp->next!=tail->next);
	
	return pos3;
 }
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	Display 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
 // 
 //		Description    :	This function displays linked list. 
 // 
 //		Returns		   :	void 
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 
void Display(struct Node *head)
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
	int pos=0;

	//call the function to add node at first position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,70);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,80);

	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	Display(first);

	pos=SearchSecLastOcc(first,last,40);
	if(pos)
	{
		printf("\n\n The element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Element is not found in the linked list.");
	}

    pos=SearchSecLastOcc(first,last,90);
	if(pos)
	{
		printf("\n\n The element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Element is not found in the linked list.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 60 70 40 30 80   no = 40
 //
 //		Output			  :	    The element is found at 4 position in the linked list
 //
 //		Input LinkedList  :		10 20 30 40 50 60 70 40 30 80   no = 90
 //
 //		Output			  :		Element is not found in the linked list.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////