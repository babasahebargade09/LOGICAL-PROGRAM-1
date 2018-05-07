////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		48.Write a program which search first occurrence of particular element from singly linear linked list. 
//		Function should return position at which element is found. 
//		Function Prototype :  int SearchFirstOcc( struct node *Head,struct node *Tail, int no ); 
//I
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int InsertLast( struct Node **head,struct Node **tail,  int no )
 {
	struct Node *newnode=NULL;

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
		*head=*tail=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		(*tail)->next=newnode;
		*tail=newnode;
		(*tail)->next=*head;
	}
	return 1;
 }
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	SearchFirstOcc 
 //
 //		Parameters		:	1. struct Node *head => Holds head pointer of list.
 //							2. struct Node *tail => Holds last node address of list.
 //							3. int no			 => Holds data which is to be insert.
 //
 //		Description     :	This function seaches first occ of data in the list and if found , 
 //							then return position.
 //
 //		Returns         :	int => position if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int SearchFirstOcc(struct Node *head,struct Node *tail,int no)
 {
	int pos=0;
	struct Node *temp=head;


	if(temp == NULL)
	{
		return 0;
	}

	do
	{
		pos++;
		if(temp->data == no)
		{
			return pos;
			break;
		}
		temp=temp->next;
	}while(temp!=head);

	return 0;
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
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;
	struct Node *last=NULL;
	int pos=0;

	//call the function to add node at first position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	Display(first);

	pos=SearchFirstOcc(first,last,40);
	if(pos)
	{
		printf("\n\n The element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Element is not found in the linked list.");
	}

    pos=SearchFirstOcc(first,last,90);
	if(pos)
	{
		printf("\n\n The element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Element is not found in the linked list.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50   no = 40
 //
 //		Output			  :	    The element is found at 4 position in the linked list
 //
 /////////////////////////////////////////////////////////////////////////////////////////////