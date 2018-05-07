////////////////////////////////////////////////////////////////////////////////////////////////
//
//		34.Write a program which accept singly linear linked list from and check 
//		whether linked list is pallindrom or not. 
//		Function Prototype :  int ListPallindrom( struct node *First ); 
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

int Count(struct Node *head)
{
	int count=0;

	if(!head)
	{
		return 0;
	}

	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	ListPallindrom 
 //
 //		Parameters		:	1. struct node *head => Holds head pointer of list.
 //
 //		Description     :	This function check whether the given linked list is pallindrom 
 //							or not.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////


 int ListPallindrom( struct Node *First	)
{	
	struct Node *temp=First;
	int i=0;

	if(First == NULL)
	{
		return 0;
	}
	
	int *p=( int * )malloc(sizeof(int) * Count(First));
	if(!p)
		return 0;

	while(temp!=NULL)
	{
		p[i++]=temp->data;
		temp=temp->next;
	}

	while(First!=NULL)
	{
		if(p[--i] != First->data)
		{
			return 0;
		}
		First=First->next;
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
	int result=0;


	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	
	InsertLast(&second,10);
	InsertLast(&second,20);
	InsertLast(&second,30);
	InsertLast(&second,20);
	InsertLast(&second,10);
	
	
	printf("\n First Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n Second Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	result=ListPallindrom(first);
	if(result)
	{
		printf("\n\n Linked list is pallindrom.");
	}
	else
	{
		printf("\n\n Linked list is not pallindrom.");
	}
	

	result=ListPallindrom(second);
	if(result)
	{
		printf("\n\n Linked list is pallindrom.");
	}
	else
	{
		printf("\n\n Linked list is not pallindrom.");
	}
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////
 //
 //		Input	:	10 20 30 40
 //		
 //		Output	:	The given linked list is not pallindrome
 //		
 //		Input	:	10 20 30 20 10
 //
 //		Output  :	The given linked list is pallindrome.
 //
 /////////////////////////////////////////////////////////////////////////////////