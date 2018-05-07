//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	15.Write a program which accepts two singly linear linked list from user and also 
//	accept range and concat elements of source singly linear linked list from that range 
//	after singly linear destination linked list. 
//	Function Prototype :  int ConcatListRange( struct node **Src  struct node **Dest int start  int end); 
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
 } ///////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	ConcatListRange 
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //							3. int start -> starting range
 //							4. int end   -> ending range
 //
 //		Description     :	This function will concate source list to destination list in given range.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 ////////////////////////////////////////////////////////////////////////////////////////////////////////

 int ConcatListRange(  struct Node **Src , struct Node **Dest , int start ,int end)
 {
	struct Node *temp1=*Dest;
	struct Node *temp2=*Src;

	if(*Src==NULL || *Dest==NULL)
	{
		return 0;
	}

	//following loop is used to reach at the end of dest linked list.
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}

	//following two loops are used to concat the src linked list with dest linked list in a given range.
	while(start-1!=0 && temp2!=NULL)
	{
		temp2=temp2->next;
		start--;end--;
	}

	while(end!=0 && temp2!=NULL)
	{
		InsertLast(Dest,temp2->data);
		temp2=temp2->next;
		end--;
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
	InsertLast(&first,60);

	InsertLast(&second,15);
	InsertLast(&second,25);
	InsertLast(&second,35);
	InsertLast(&second,45);
	InsertLast(&second,55);
	InsertLast(&second,65);
	
	printf("\n\n First Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Second Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	//This function will concate two singly lineat linked list.
	ConcatListRange(&first,&second,2,5);

	printf("\n\n After concatination of two linked list => ");
	DisplayList(second);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :		10 20 30 40 50 60 .   
 //
 //     Dest Linked list   :		15 25 35 45 55 65 	
 //
 //		Output			   :		15 25 35 45 55 65 20 30 40 50 
 //
 /////////////////////////////////////////////////////////////////////////////////////////////