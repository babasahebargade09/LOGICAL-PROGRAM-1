///////////////////////////////////////////////////////////////////////////////////////////////
//
//	56.Write a program which accept singly linear linked list from user and sort that linked 
//	list in descending order. 
//	Function Prototype :  int ListSortDec( struct node **Head, struct node **Tail); 
//
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
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
int InsertLast(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	newnode=(struct Node *)malloc(sizeof(struct Node));

	if(newnode == NULL)
	{
		return 0;
	}
	
	newnode->data=no;
	newnode->next=newnode;

	if(*head == NULL)
	{
		*head=*tail=newnode;
		newnode->next=*head;
	}
	else
	{
		(*tail)->next=newnode;
		newnode->next=*head;
		*tail=newnode;
	}
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	ListSortDec
//
//		Description		:	This function sort the elements of linked list,in descending order.
//
//		Returns			:  1 on success otherwise return 0
//
//////////////////////////////////////////////////////////////////////////////////////////////

int ListSortDec(struct Node **head,struct Node **tail)
{
	struct Node *temp1=*head;
	struct Node *temp2=(*head)->next;
	struct Node *temp3=NULL;

	if(*head == NULL || (*head)->next == NULL)
	{
		return 0;
	}
	
	do
	{
		if(temp1->data < temp2->data)
		{
			if(temp1==*head && temp2==temp1->next)
			{
				temp1->next=temp2->next;
				temp2->next=*head;
				*head=temp2;
				(*tail)->next=*head;
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
	
	}while(temp2!=*head);
	*tail=temp1;	 
	
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
	struct Node *temp=head;

	if(temp == NULL)
	{
		return;
	}

	do
	{
		printf("|%d|->",temp->data);
		temp=temp->next;

	}while(temp!=head);
}

int main()
{

	struct Node *first=NULL;
	struct Node *last=NULL;

	
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,40);

	printf("\n\n The linked list is => ");
	DisplayList(first);


	ListSortDec(&first,&last);
	printf("\n\n After sorting , the linked list is => ");
	DisplayList(first);

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////
//
//	Linked List	: 10 30 20 50 40
//
//	Output		: 50 40 30 20 10
//
////////////////////////////////////////////////////////////////////////////