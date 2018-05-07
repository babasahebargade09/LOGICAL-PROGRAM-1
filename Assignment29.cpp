////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		29.Write a program which accept two singly linear linked list and then merge this two list in 
//		   such a way that resultant may contain elements alternatively from one list and other list. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
 //		Function Name  :	CopyAlt 
 //
 //		Parameters	   :	1.struct node *head1 => Holds starting address of first list.
 //                         2.struct node *head2=> Holds starting address of second list.
 //							3.struct node **head3=> Holds starting address of third(new)list. 
 //
 //		Description    :	This function copy contents of source and destination list into
 //							thrid list alternatively.
 // 
 //		Returns		   :	int => on success return 1,otherwise return -1
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 

 int CopyAlt(struct Node *head1,struct Node *head2,struct Node **head3)
 {
	 	struct Node *newnode=NULL;
		struct Node *temp1=*head3;

		if(head1 == NULL || head2 == NULL)
		{
			return -1;
		}
		
		int flag=1;

		while(head1!=NULL || head2!=NULL)
		{
			newnode=(struct Node *)malloc(sizeof(struct Node));

			if(newnode == NULL)
			{
				return -1;
			}

			newnode->next=NULL;
			
			if(flag==1 && head1!=NULL)
			{
				newnode->data=head1->data;
				head1=head1->next;
				flag=0;
			}
			else if( head2!=NULL)
			{
				newnode->data=head2->data;
				head2=head2->next;
				flag=1;
			}

			if(*head3 == NULL)
			{
				*head3=temp1=newnode;
			}
			else
			{
				temp1->next=newnode;
				temp1=newnode;
			}

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
	struct Node *second=NULL;
	struct Node *third=NULL;

	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
	InsertLast(&first,60);
 
	InsertLast(&second,11);
	InsertLast(&second,22);
	InsertLast(&second,33);
	InsertLast(&second,44);
	InsertLast(&second,55);
	InsertLast(&second,65);
	InsertLast(&second,75);
	

	printf("\n The first linked list is =>");
	DisplayList(first);

	
	printf("\n The second linked list is =>");
	DisplayList(second);

	CopyAlt(first,second,&third);
	printf("\n After copying content alternatively, the Linked list is => ");
	DisplayList(third);


	getch();
	return 0;
 }

 ///////////////////////////////////////////////////////////////////////////////
 //
 //		Input 1st List	:	10 20 30 40 50 60
 //
 //     Input 2nd List  :   11 22 33 44 55 65 75
 //
 //		Output			:   10 11 20 22 30 33 40 44 50 55 60 65 75
 //
 ////////////////////////////////////////////////////////////////////////////////