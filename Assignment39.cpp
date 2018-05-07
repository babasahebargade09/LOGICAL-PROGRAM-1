////////////////////////////////////////////////////////////////////////////////////////////////
//
//		38.Write a program which accepts two singly linear linked list from user 
//		and compare both linked list but only last N nodes. 
//		Function Prototype :  int ListICmp( struct node *First struct node *Second int N)
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
 //		Function Name   :	ListICmp
 //
 //		Parameters		:	1. struct Node *First => Holds first pointer of first list.
 //							2. struct Node *second=> Holds pointer of second list.
 //							3. int N => Number upto which we have to compare both lists.	
 //
 //		Description     :	This function compare two singly linked list but only last N nodes.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int ListNCmp(struct Node *First,struct Node *Second,int N)
 {
	struct Node *temp1=First;
	struct Node *temp2=Second;

	if(temp1 == NULL || temp2 == NULL )
	{
		return -1;
	}
	
	//Following two loops are used to reach at the required position.
	while(N!=0 && temp1!=NULL && temp2!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
		N--;
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
		First=First->next;
		Second=Second->next;
	}

	//Following loop is used for compare two linked list.
	while(First!=NULL && Second!=NULL )
	{
		if(First->data != Second->data)
		{
			return -1;
		}
		First=First->next;
		Second=Second->next;
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
	

	InsertLast(&second,35);
	InsertLast(&second,25);
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

	result=ListNCmp(first,second,4);

	if(result == 1)
	{
		printf("\n\n Both linked list are same upto 4 nodes.");
	}
	else
	{
		printf("\n\n Both linked list are not same upto 4 nodes.");
	}

	printf("\n\n First linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Third linked list is => ");
	DisplayList(third);
	
	//This function sorts list in descending order.
	result=0;

	result=ListNCmp(first,third,4);

	if(result == 1)
	{
		printf("\n\n Both linked list are same upto 4 nodes.");
	}
	else
	{
		printf("\n\n Both linked list are not same upto 4 nodes.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////
 //
 //		Input 1st List	:	30 20 10 40 60 50
 //
 //		Input 2nd List	:   35 25 10 40 60 50
 //
 //		Output			:   Both linked list are same upto last 4 nodes. 
 //
 //		Input 1st List	:	30 20 10 40 60 50
 //
 //		Input 2nd List	:   30 25 10 40 65 55 
 //
 //		Output			:   Both linked list are not same upto 4 nodes.. 
 //
 /////////////////////////////////////////////////////////////////////////////////