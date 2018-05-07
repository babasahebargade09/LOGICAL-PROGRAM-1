/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	43.Write a program which add new node in singly circular linked list at specified position. 
//	Function Prototype :  int InsertAtPosition( struct node **Head, struct node **Tail,  int no, int pos ); 
//I
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node *next;
};


//////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		InsertFirst
//
//		Parameters	  :		1.struct Node **head => starting address of list.
//							2.struct Node **tail => ending address of list.
//							3.int no => data which we have to add.
//	
//		Description	  :		This function adds new element at the starting of list.
//
//		Returns		  :		int => 1 if function succeeds otherwise 0
//
//////////////////////////////////////////////////////////////////////////////////////
int InsertFirst(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	//allocate memory for new node
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode == NULL)
	{
		return 0;
	}

	newnode->data=no;
	newnode->next=NULL;

	if(*head == NULL)
	{
		*head=*tail=newnode;
		(*tail)->next=*head;
	}
	else
	{
		newnode->next=*head;
		*head=newnode;
		(*tail)->next=*head;
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		InsertLast
//
//		Parameters	  :		1.struct Node **head => starting address of list.
//							2.struct Node **tail => ending address of list.
//							3.int no => data which we have to add.
//							
//		Description	  :		This function adds new element at the last position of list.
//
//		Returns		  :		int => 1 if function succeeds otherwise 0
//
//////////////////////////////////////////////////////////////////////////////////////
int InsertLast(struct Node **head,struct Node **tail,int no)
{
	struct Node *newnode=NULL;

	//allocate memory for new node
	newnode=(struct Node *)malloc(sizeof(struct Node));
	if(newnode == NULL)
	{
		return 0;
	}

	newnode->data=no;
	newnode->next=NULL;

	if(*head == NULL)
	{
		*head=*tail=newnode;
		(*tail)->next=*head;
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
	struct Node *temp=head;

	int count=0;

	do
	{
		temp=temp->next;
		count++;
	}while(temp!=head);

	return count;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		InsertAtPosition
//
//		Parameters	  :		1.struct Node **head => starting address of list.
//							2.struct Node **tail => ending address of list.
//							3.int no => data which we have to add.
//							4.int pos=> position at which we have to add node.
//
//		Description	  :		This function adds new element at the specific position of list.
//
//		Returns		  :		int => 1 if function succeeds otherwise 0
//
//////////////////////////////////////////////////////////////////////////////////////

int InsertAtPosition(struct Node **head,struct Node **tail,int no,int pos)
{
	struct Node *newnode=NULL;
    struct Node *temp=NULL;
	int i;

	if(*head == NULL)
	{
		return 0;
	}
	else if( pos == 1 )
	{
		InsertFirst(head ,tail , no); 
	}
	else if(pos == (Count(*head)) + 1)
	{
		InsertLast(head ,tail , no); 
	}
	else if( (pos > Count(*head)))
	{
		return 0;
	}
	else
	{
		//allocate memory for node
		newnode=(struct Node *)malloc(sizeof(struct Node));

		//check whether memory is allocated or not.
		if(newnode == NULL)
		{
			return 0;
		}

		//fill node with the data.
		newnode->next=NULL;
		newnode->data=no;
	

		//Add node at last position.

		for( i=1,temp=*head; i<(pos-1) && temp->next!=NULL; i++,temp=temp->next);
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
		
	}
	return 1;

}
//////////////////////////////////////////////////////////////////////////////////////
//
//		Function name :		DisplayList
//
//		Parameters	  :		1.struct Node *head => starting address of list.
//	
//		Description	  :		This function will display linked list.
//
//		Returns		  :		void
//
//////////////////////////////////////////////////////////////////////////////////////

void DisplayList(struct Node *head)
{
	struct Node *temp=head;

	if(temp)
	{
		do
		{
			printf("|%d|->",temp->data);
			temp=temp->next;
		}while(temp!=head);	
	}
	else
	{
		printf("\n\n Linked list is empty.");
	}
}
int main()
{
	struct Node *first=NULL;
	struct Node *last=NULL;

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);

	printf("\n\n The linked list is => ");
	DisplayList(first);

	InsertAtPosition(&first,&last,15,2);
	InsertAtPosition(&first,&last,25,4);
	InsertAtPosition(&first,&last,45,7);
	InsertAtPosition(&first,&last,55,8);

	printf("\n\n After adding nodes at the specific position the linked list is=> ");
	DisplayList(first);

	getch();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//		Linked list is	:	10 , 20 , 30 , 40 , 50
//
//		Input			:	Node(pos) => 15(2) , 25(4) , 45(7), 55(8) 
//
//		Output			:	 After adding nodes at the specific position the linked list is=> 
//							10 15 20 25 30 40 45 55 50 
//
//////////////////////////////////////////////////////////////////////////////////////////////