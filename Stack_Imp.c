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
uint8_t*balancedParentheses(uint8_t* expression);


//char stacklength 5;
//int stack[5]

void main(void)  
{
	uint8_t u8_SendRecieved;
	uint32_t u32_operation;
	uint8_t exp[20];

	while(1)
	{
    	printf("press 1 to push\n2 to pop\n3 to print the stack\n4 to check an expression\nnumber is :");
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
			case 4:
			printf("write the expression : ");
			scanf("%s",exp);
			printf("%s\n",balancedParentheses(exp));
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
	//printf("value: %d is popped\n",tempdata);	
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
uint8_t*balancedParentheses(uint8_t* expression)
{
	uint8_t check=0;
	uint8_t i=0;
	uint8_t temp;
	while(expression[i]!='\0')
	{
		if(expression[i]=='{'||expression[i]=='(')
		{
			push(expression[i]);
			check++;
		}
		else if(expression[i]=='}'||expression[i]==')')
		{
			if(!check)
				return "unbalanced";
			
			temp=pop();
			check--;
			if(!((expression[i]=='}'&&temp=='{')||(expression[i]==')'&&temp=='(')))
				{
					while(check)
					{
						pop();
						check--;
					}
					return "unbalanced";
				}
		}
		i++;
	}
	if(check)
	{
		while(check)
		{
			pop();
			check--;
		}
		return "unbalanced";
	}
return "balanced";	
}


