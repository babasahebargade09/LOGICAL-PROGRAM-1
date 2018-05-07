////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		51.Write a program which searches all occurrence of particular element from singly circular linked list. 
//		Function should return number of occurance of that element. 
//		Function Prototype :  int SearchAll( struct node *Head, struct node *Tail,  int no ); 
//
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
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	SearchAll
 //
 //		Parameters		:	1. struct Node *head => Holds head pointer of list.
 //							2. struct Node *tail => Holds last node address of list.
 //							3. int no			 => Holds data which is to be insert.
 //
 //		Description     :	This function seaches all occ of element in the list and if found , 
 //							then return number of occ of that element.
 //
 //		Returns         :	int => number of occ of an element if function succeeds, otherowise return 0.
 //
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////

 int SearchAll(struct Node *head,struct Node *tail,int no)
 {
	int count=0;
	struct Node *temp=head;


	if(head == NULL)
	{
		return 0;
	}

	do
	{
		if(temp->data == no)
		{
			count++;
		}
		temp=temp->next;
	}while(temp!=head);

	return count;
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
	int count=0;

	//call the function to add node at first position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,70);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,80);

	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	Display(first);

	count=SearchAll(first,last,40);
	if(count)
	{
		printf("\n\n The element is found  %d times in the linked list.",count);
	}
	else
	{
		printf("\n\n Element is not found in the linked list.");
	}

    count=SearchAll(first,last,90);
	if(count)
	{
		printf("\n\n The element is found  %d times in the linked list.",count);
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
 //		Input Linked List :		10 20 30 40 50 60 70 40 30 80   no = 40
 //
 //		Output			  :	    The element is found  2 times in the linked list.
 //
 //		Input LinkedList  :		10 20 30 40 50 60 70 40 30 80   no = 90
 //
 //		Output			  :		Element is not found in the linked list.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////