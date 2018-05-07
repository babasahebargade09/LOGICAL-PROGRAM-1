////////////////////////////////////////////////////////////////////////////////////////////////
//
//		37.Write a program which accepts two singly linear linked list from user 
//		and compare both linked list. 
//		Function Prototype :  int ListCmp( struct node *First struct node *Second)
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

	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
 }

 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	ListCmp
 //
 //		Parameters		:	1. struct Node *First => Holds first pointer of first list.
 //							2. struct Node *second=> Holds pointer of second list.
 //
 //		Description     :	This function compare two singly linked list.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int ListCmp(struct Node *First,struct Node *Second)
 {
	struct Node *temp1=First;
	struct Node *temp2=Second;
	
	if(temp1 == NULL || temp2 == NULL || Count(temp1) != Count(temp2))
	{
		return -1;
	}
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data != temp2->data)
		{
			return -1;
		}
		temp1=temp1->next;
		temp2=temp2->next;
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
	struct Node *third=NULL;

	//call the function to add node at last position.
	InsertLast(&first,30);
	InsertLast(&first,20);
	InsertLast(&first,10);
	InsertLast(&first,40);
	InsertLast(&first,60);
	InsertLast(&first,50);

	InsertLast(&second,30);
	InsertLast(&second,20);
	InsertLast(&second,10);
	InsertLast(&second,40);
	InsertLast(&second,60);
	InsertLast(&second,50);

	InsertLast(&third,30);
	InsertLast(&third,25);
	InsertLast(&third,10);
	InsertLast(&third,40);
	InsertLast(&third,65);
	InsertLast(&third,55);

	printf("\n\n First linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Second linked list is => ");
	DisplayList(second);
	
	//This function sorts list in descending order.
	int result=0;

	result=ListCmp(first,second);

	if(result == 1)
	{
		printf("\n\n Both linked list are same.");
	}
	else
	{
		printf("\n\n Both linked list are not same.");
	}

	printf("\n\n First linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Third linked list is => ");
	DisplayList(third);
	
	//This function sorts list in descending order.
	result=0;

	result=ListCmp(first,third);

	if(result == 1)
	{
		printf("\n\n Both linked list are same.");
	}
	else
	{
		printf("\n\n Both linked list are not same.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////
 //
 //		Input 1st List	:	30 20 10 40 60 50
 //
 //		Input 2nd List	:   30 20 10 40 60 50
 //
 //		Output			:   Both linked list are same. 
 //
 //		Input 1st List	:	30 20 10 40 60 50
 //
 //		Input 2nd List	:   30 25 10 40 65 55 
 //
 //		Output			:   Both linked list are not same. 
 //
 /////////////////////////////////////////////////////////////////////////////////