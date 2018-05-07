//////////////////////////////////////////////////////////////////////////////////////////
//
//	21.Write a program which copies contents of source singly linear linked list 
//     whose addition of digits is even number to destination singly linear linked list. 
//
//////////////////////////////////////////////////////////////////////////////////////////

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
 //		Function Name   :	LLCopyEx
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will copy those elements of source list into destination list,
 //							whose digits sum is even number.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int LLCopyEx(  struct Node *Src , struct Node **Dest )
 {
	struct Node *temp1=*Dest;
	struct Node *newnode=NULL;
	int sum=0,num=0;
	
	//If source linked list is empty.
	if(Src == NULL )
	{
		return -1;
	}

	
	//Following loop is used to copy content from src list to dest list.
	while(Src!=NULL)
	{
		num=Src->data;
		while(num!=0)
		{
			sum=sum+num%10;
			num=num/10;
		}
		if(sum % 2 == 0)
		{
			//Allocate memory for node.
			newnode=(struct Node *)malloc(sizeof(struct Node));

			//check whether memory is allocated or not.
			if(newnode == NULL)
			{
				return -1;
			}

			//Assigning data
			newnode->next=NULL;
			newnode->data=Src->data;

			//Add node in the linked list
			if(*Dest == NULL)
			{
				*Dest=temp1=newnode;
			}
			else
			{
				temp1->next=newnode;
				temp1=newnode;
			}
	
		}
		Src=Src->next;
		sum=0;
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
	InsertLast(&first,15);
	InsertLast(&first,25);
	InsertLast(&first,35);
	InsertLast(&first,45);
	InsertLast(&first,55);
	
	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	
	//This function will concate two singly lineat linked list.
	LLCopyEx(first,&second);

	printf("\n\n After copying content dest. linked list is=> ");
	DisplayList(second);

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :	15 25 35 45 55
 //
 //		Dest linked list   :	Empty(NULL)list.
 //
 //		Output(Dest list)  :	15 35 55   
 //
 /////////////////////////////////////////////////////////////////////////////////////////////