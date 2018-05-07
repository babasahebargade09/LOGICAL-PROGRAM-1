////////////////////////////////////////////////////////////////////////////////////////////////
//
//		27.Write a program which accept source singly linear linked list from 
//		   user and reverse that linear linked. 
//	       Function Prototype :  int ListReverse(struct node **Src);
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
 ///////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Function Name   :	Count
 //
 //		Parameters		:	1.struct Node *head   => Holds head pointer of list.
 //
 //		Description		:	This function returns number of nodes in the linked list.
 //
 //     Returns			:   int => Number of nodes in the linked list.  
 //
 ////////////////////////////////////////////////////////////////////////////////////////////

 int Count(struct Node *head)
 {
	int count=0;

	if(head)
	{
		while(head)
		{
			head=head->next;
			count++;
		}
	}
	else
	{
		return 0;
	}
	return count;
 }
///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	ListReverse 
 //
 //		Parameters	   :	1.struct node **Src => Holds starting address of list. 
 // 
 //		Description    :	This function reverse source linked list. 
 // 
 //		Returns		   :	int => on success return 1,otherwise return -1
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 

 int ListReverse(struct Node **Src)
 {
	 struct Node *temp=*Src;
	 
	 if(*Src == NULL)
	 {
		return -1;	 
	 }
 
	 int *p=(int *) malloc (sizeof(int) * Count(*Src));
	 int i=0;
	 
	 while(temp!=NULL)
	 {
		 p[i++]=temp->data;
		 temp=temp->next;
	 }

	 temp=*Src;

	 while(temp!=NULL)
	 {
		 temp->data=p[--i];
		 temp=temp->next;
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

	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
 
	printf("\n The linked list is =>");
	DisplayList(first);

	ListReverse(&first);
	printf("\n The linked list is =>");
	DisplayList(first);

	getch();
	return 0;
 }

 ///////////////////////////////////////////////////////////////////////////////
 //
 //		Input	:	10 20 30 40 50
 //
 //		Output	:   50 40 30 20 10
 //
 ////////////////////////////////////////////////////////////////////////////////