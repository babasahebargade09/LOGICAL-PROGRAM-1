//////////////////////////////////////////////////////////////////////////////////////////
//
//	23.Write a program which accept source singly linear linked list and destination 
//     singly linear linked list and check whether source list is sub list of destination
//     list. Function returns first position at which sub list found. 
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
 //		Function Name   :	SubList
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //							2. struct Node *Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will check whether source list is sub list of dest list
 //							or not. If yes then it return position of sublist.
 //
 //		Returns         :	int => position of sublist if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int SubList(  struct Node *Src , struct Node *Dest )
 {
	struct Node *temp1=Src;
	struct Node *temp2=Dest;
	int pos=1;
	
	//If source linked list is empty.
	if(Src == NULL || Dest == NULL)
	{
		return 0;
	}

	while(temp1!=NULL  && temp2!=NULL)
	{
		if(temp1->data == temp2->data)
		{
			temp2=temp2->next;
			temp1=temp1->next;
		}
		else if(temp1 == Src)
		{
			pos++;
			temp2=temp2->next;
		}
		else
		{
			pos++;
			temp1=Src;
		}
	}
	if(temp1 == NULL)
	{
		return pos;
	}
	else
	{
		return 0;
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
	struct Node *second=NULL;
	struct Node *third=NULL;
	
	//call the function to add node at first position.
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
	InsertLast(&first,60);
	
	InsertLast(&second,10);
	InsertLast(&second,20);
	InsertLast(&second,30);
	InsertLast(&second,40);
	InsertLast(&second,50);
	InsertLast(&second,60);
	InsertLast(&second,70);
	InsertLast(&second,80);
	
	InsertLast(&third,20);
	InsertLast(&third,30);
	InsertLast(&third,50);
	InsertLast(&third,60);
	

	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(first);
 
	printf("\n\n Destination Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	//This function check whether source list is sublist of dest list or not.
	
	int pos=SubList(first,second);
	if(pos == 0)
	{
		printf("\n\n Sublist not fount.");
	}
	else
	{
		printf("\n\n First sublist is fount at position => %d",pos);
	}


	printf("\n\n Source Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(third);

	printf("\n\n Destination Linked list is => ");
	//call to DisplayList function to display linked list.
	DisplayList(second);
 
	//This function check whether source list is sublist of dest list or not.
	
	pos=SubList(third,second);
	if(pos == 0)
	{
		printf("\n\n Sublist not fount.");
	}
	else
	{
		printf("\n\n First sublist is fount at position => %d",pos);
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Source Linked List :	30 40 50 60
 //
 //		Dest linked list   :	10 20 30 40 50 60 70 80 
 //
 //		Output			   :	First sublist is found at position => 3   
 //
 //		Source Linked List :	20 30 50 60
 //
 //		Dest linked list   :	10 20 30 40 50 60 70 80 
 //
 //		Output			   :	Sublist not found.   
 //
 /////////////////////////////////////////////////////////////////////////////////////////////