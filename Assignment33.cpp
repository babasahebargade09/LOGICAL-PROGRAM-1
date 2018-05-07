///////////////////////////////////////////////////////////////////////////////////////////////////
//
//		33.Write a program which accepts two singly linear linked list from user and check whether
//      they are intersecting or not. 
//      Function Prototype :  int ListIntersect( struct node *Src , struct node *Dest); 
//
////////////////////////////////////////////////////////////////////////////////////////////////////

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
int Count(struct Node *head)
{
	int count=0;
	if(!head)
	{
		return 0;
	}

	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	ListIntersect
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //							2. struct Node *Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will check whether two linked list are intersecting or not.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int ListIntersect(struct Node *Src,struct Node *Dest)
 {
	int length1,length2,difference;

	struct Node *temp1=Src;
	struct Node *temp2=Dest;

	if(Src == NULL || Dest == NULL)
	{
		return 0;
	}

	length1=Count(Src);
	length2=Count(Dest);

	if(length1 < length2)
	{
		temp1=Dest;
		temp2=Src;
		difference = length2 - length1;
	}
	else
	{
		temp1=Src;
		temp2=Dest;
		difference = length1 - length2;
	}

	for(int i=0;i<difference;i++)
	{
		temp1=temp1->next;
	}

	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1 == temp2)
		{
			return temp1->data;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return 0;
 }

 int Convert(struct Node **first , struct Node **second , struct Node *third)
 {
	 if(first == NULL || second == NULL || third == NULL)
	 {
		return 0;
	 }

	 struct Node *temp1=*first;
	 struct Node *temp2=*second;

	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	while(temp2->next!=NULL)
	{
		temp2=temp2->next; 
	}

	temp1->next=third;
	temp2->next=third;

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
	struct Node *third=NULL;

	int result=0;
	
	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	
	InsertLast(&second,15);
	InsertLast(&second,25);
	InsertLast(&second,35);
	
	InsertLast(&third,100);
	InsertLast(&third,200);
	InsertLast(&third,300);
	
	printf("\n The source Linked list is => ");
	DisplayList(first);

	printf("\n The destination Linked list is => ");
	DisplayList(second);

	printf("\n The destination Linked list is => ");
	DisplayList(third);

	
	result=ListIntersect(first,second);
	if(result)
	{
		printf("\n\n Both linked list are intersect at %d node of 3rd list",result);
	}
	else
	{
		printf("\n\n Not intersect");
	}

	Convert(&first,&second,third);
	
	result=ListIntersect(first,second);
	if(result)
	{
		printf("\n\n Both linked list are intersect at %d node of 3rd list",result);
	}
	else
	{
		printf("\n\n Not intersect");
	}

	getch();
	return 0;
 }

 