//////////////////////////////////////////////////////////////////////////////////////////
//
//	57.Write a program which accepts two singly linear linked list from user and 
//	compare both linked list. 
//	Function Prototype :  int ListCmp( struct node *SrcHead,struct node *SrcTail,
//	struct node *DestHead,struct node *DestTail); 
//
///////////////////////////////////////////////////////////////////////////////////////////
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
int Count(struct Node *head)
{	
	int count=0;
	struct Node *temp=head;

	if(head == NULL)
	{
		return count;
	}

	do
	{
		count++;
		temp=temp->next;
	
	}while(temp!=head);

	return count;
}
///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	Listcmp
 //
 //		Parameters	   :	1.struct Node *SrcHead => Holds head pointer of source list. 
 //							2.struct Node *SrcTail => Holds tail pointer of source list. 
 //							3.struct Node *DestHead=> Holds head pointer of destination list. 
 //							4.struct Node *Destail => Holds tail pointer of destination list. 
 //
 //		Description    :	This compare the source and the destination linked list.
 // 
 //		Returns		   :	1 on success otherwise return 0 on failure.
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
int ListCmp( struct Node *SrcHead,struct Node *SrcTail,struct Node *DestHead,struct Node *DestTail)
{

	struct Node *temp1=SrcHead;
	struct Node *temp2=DestHead;

	if(temp1 == NULL || temp2 == NULL || Count(temp1)!=Count(temp2))
	{
		return 0;
	}

	do
	{
		if(temp1->data != temp2->data)
		{
			return 0;
		}
		else
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
	
	}while(temp1!=SrcHead);

	return 1;
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

	struct Node *first1=NULL;
	struct Node *last1=NULL;

	struct Node *first2=NULL;
	struct Node *last2=NULL;

	int result=0;
	
	InsertLast(&first1,&last1,10);
	InsertLast(&first1,&last1,20);
	InsertLast(&first1,&last1,30);
	InsertLast(&first1,&last1,40);
	InsertLast(&first1,&last1,50);

	printf("\n\n The first linked list is => ");
	Display(first1);


	InsertLast(&first2,&last2,10);
	InsertLast(&first2,&last2,20);
	InsertLast(&first2,&last2,30);
	InsertLast(&first2,&last2,40);
	InsertLast(&first2,&last2,50);
	//InsertLast(&first2,&last2,65);

	printf("\n\n The second linked list is => ");
	Display(first2);

	
	result=ListCmp(first1,last1,first2,last2);
	
	if(result)
	{
		printf("\n\n Both linked list are equal.");
	}
	else
	{
		printf("\n\n Both linked list are not equal.");
	}
	
	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		Source linked list	: 10 20 30 40 50
//
//		Dest linked list	: 10 20 30 40 50
//
//		Output				: Both linked list are equal.
//
////////////////////////////////////////////////////////////////////////////////////
