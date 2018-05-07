/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	19.Write a program which copies contents of source singly linear linked list 
//	to destination singly linear linked list which lies between the particular range which 
//	is accepted from user. 
//	Function Prototype :  int LLCopyRange(struct node **Src  struct node **Dest int start int end); 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
 //		Function Name   :	LLCopyRange
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //							3. int start => starting of range
 //							4. int end   => ending of range
 //
 //		Description     :	This function will copy elements of source list into destination list,
 //							in a given range.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int LLCopyRange(  struct Node *Src , struct Node **Dest ,int start , int end)
 {
	struct Node *temp=Src;

	//If any one of the linked list is empty.
	if(Src == NULL)
	{
		return 0;
	}

	//Following two loops are used to reach at the specific position from end of list.
	while(start-1!=0 && temp!=NULL)
	{
		temp=temp->next;
		start--;
		end--;
	}
	while(end!=0 && temp!=NULL)
	{
		InsertLast(Dest,temp->data);
		temp=temp->next;
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

	
	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	
	//This function will concate two singly lineat linked list.
	LLCopyRange(first,&second,2,4);

	printf("\n\n After copying content dest. linked list is=> ");
	DisplayList(second);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :	10 20 30 40 50
 //
 //		Dest linked list   :	Empty(NULL)list.
 //
 //		Range			   :    2-4
 //
 //		Output(Dest list)  :	20 30 40
 //
 /////////////////////////////////////////////////////////////////////////////////////////////