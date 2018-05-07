///////////////////////////////////////////////////////////////////////////////////////////////////
//
//	28.Write a program which accept singly linear linked list from user and check whether list 
//	contains loop or not. 
//	Function Prototype :  int LoopChk(struct node *Src); 
//
///////////////////////////////////////////////////////////////////////////////////////////////////

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
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int InsertLast( struct Node **head,  int no )
 {
	struct Node *newnode=NULL;
	static struct Node *temp=NULL;

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
		*head=temp=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
	return 1;
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	LoopChk
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //
 //		Description     :	This function will check whether source list contains loop or not. 
 //
 //		Returns         :	int => 1 on loop found, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int LoopChk(struct Node *Src)
 {
	struct Node *ftemp1=Src;
	struct Node *stemp2=Src;

	if(Src == NULL)
	{
		return 0;
	}

	while(ftemp1 && stemp2)
	{
		ftemp1=ftemp1->next;
		
		if(ftemp1 == stemp2)
		{
			return 1;
		}

		if(ftemp1 == NULL)
		{
			return 0;
		}

		ftemp1=ftemp1->next;
		if(ftemp1 == stemp2)
		{
			return 1;
		}
		stemp2=stemp2->next;
	}
	return 0; 
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
 
 int CreateLoop(struct Node **head)
 {
	struct Node *temp1=*head;
	struct Node *temp2=*head;
	
	if(*head == NULL)
		return 0;
	
	while(temp1->next!=NULL)
	{
		temp1=temp1->next->next;
		temp2=temp2->next;
	}
	temp1->next=temp2;
	return 1;
 }
 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *second=NULL;
	int result;

	//call the function to add node at last position.
	InsertLast(&second,10);
	InsertLast(&second,20);
	InsertLast(&second,30);
	InsertLast(&second,40);
	InsertLast(&second,50);
	
	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	result = LoopChk(second);
	if(result)
	{
		printf("\n\n Loop is found in the linked list.");
	}
	else
	{
		printf("\n\n Loop is not found in the linked list.");
	}

	CreateLoop(&second);

	result = LoopChk(second);
	if(result)
	{
		printf("\n\n Loop is found in the linked list.");
	}
	else
	{
		printf("\n\n Loop is not found in the linked list.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		List	=>	10 20 30 40 50				   
 //
 //		output	=> Loop is not found in the linked list.
 /////////////////////////////////////////////////////////////////////////////////////////////