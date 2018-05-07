////////////////////////////////////////////////////////////////////////////////////////////////
//
//		32.Write a program which accept singly linear linked list from user 
//		   and reverse the linked list from particular range. 
//		   Function Prototype :  int ListRevRange( struct node **Src int start, int end)
//
////////////////////////////////////////////////////////////////////////////////////////////////
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
 //		Function Name  :	ListRevRange 
 //
 //		Parameters	   :	1.struct node **Src => Holds head pointer of list. 
 // 
 //		Description    :	This function reverse the source linked list in given range. 
 // 
 //		Returns		   :	1 on success otherwise returns -1.
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 

 int ListRevRange( struct Node **Src , int start, int end)
 {
	struct Node *temp1=*Src;
	struct Node *temp2=*Src;
	int i=0;

	if(Src==NULL)
	{
		return -1;
	}

	int *p=(int *)malloc(sizeof(int) * (end - start)+1);
	if(p == NULL)
	{
		return -1;
	}

	//This loop is used to reach at the start position.
	while(start-1!=0 &&  temp1!=NULL)
	{
		temp1=temp1->next;
		start--;
		end--;
	}
	temp2=temp1;
	
	//copy content in the given range in stack.  
	while(end!=0 && temp1!=NULL)
	{
		p[i++]=temp1->data;
		temp1=temp1->next;
		end--;
	}

	//copy content from stack to linked list.
	while(temp2!=NULL && i>0)
	{
		temp2->data=p[--i];
		temp2=temp2->next;
	}


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

	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
	InsertLast(&first,60);
	InsertLast(&first,70);
	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);

	ListRevRange(&first,3,6);
	printf("\n\n After reversing list in given range, list is =>");
	DisplayList(first);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 60 70  start=3 end =6 
 //
 //		Output			  :		10 20 60 50 40 30 70
 //
 /////////////////////////////////////////////////////////////////////////////////////////////