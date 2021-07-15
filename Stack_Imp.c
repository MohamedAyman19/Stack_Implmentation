#include<stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
typedef struct Node
{
uint8_t data;
struct Node *next;	
}Node;

Node* head=NULL;

void push(uint8_t u8_data);
uint8_t pop();
void pintstack();



//char stacklength 5;
//int stack[5]

void main(void)  
{
	uint8_t u8_SendRecieved;
	uint32_t u32_operation;

	while(1)
	{
    	printf("press 1 to push\n2 to pop\n3 to print the stack\nnumber is :");
	    scanf("%d",&u32_operation);
		switch(u32_operation)
		{
			case 1:
			printf("write the data value : ");
			scanf("%d",&u8_SendRecieved);
			push(u8_SendRecieved);
			break;
			case 2:
			u8_SendRecieved=pop();
			break;
			case 3:
			pintstack();
			break;
			default:
			printf("Enter a valid choice\n");
			break;
			
			
		}
	}

	
}

void push(uint8_t u8_data)
{
	Node* newnode;
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)
	{
		printf("heap memory is full\n");
	}
	else
	{
		(newnode->data)=u8_data;
		(newnode->next)=head;
		head=newnode;
	}
	
}
uint8_t pop()
{
	uint8_t tempdata;
	if(head==NULL)
	{
	printf("stack is empty\n");	
	return 0;
	}
	Node*temp=head;
	head=head->next;
	tempdata=temp->data;
	free(temp);
	printf("value: %d is popped\n",tempdata);	
	return tempdata;
}
void pintstack()
{
	if(head==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		Node*temp=head;
		printf("values in the stack are :");
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	
}




