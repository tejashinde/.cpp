#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class STACKL
{
	private :	int operand;
				STACKL *next;
	public :	STACKL(){} //Null Constructor
	
	friend void push (STACKL *&TOP, int data);
	friend void pop (STACKL *&TOP, int data);
	friend int evalPost(char str[]);			
};

void push(STACKL *&TOP, int data)
{
	//Value of last node of an empty stack
		STACKL *stk = NULL;
	//Every addition of value to empty stack will create new stacck node
	//Value of last node created, changes durong execution
	//Top can refer to any pointer variable 
	
	STACKL *temp;
	temp = new STACKL;
	if(temp == NULL)
		exit(1);
	temp -> operand = data;
	temp -> next = top;
	TOP = temp;	
}

void pop(STACKL *&TOP, int data)
{
	STACKL *temp;
	temp = TOP;
	data = temp -> operand;
	TOP = temp -> next;
	
	delete(temp)
}

int evalPost(char str[])
{
	//postfix is not built in datatype
	//postfix form is stored in char[]
	//every character value is treated as an integer value
	
	int i,j,fp,sp,value;
	char ch;
	STACKL *stk = NULL;
	i = 0;
	while(str[i]!='\0')
	{
		ch = str[i];
		
		switch(ch)
		{
			case '+' : 
				j = 1; 
				break;
			
			case '-' : 
				j = 2;
				break;
			
			case '*' :
				j = 3;
				break;	
			
			case '/' :
				j = 4;
				break;
			
			case 32 :
				j = 0;
				break;
			
			default:
				j; //blank space is not pushed in stack
				
			value ch-'0';
			push (stk,value);				
		}
		if(j)
		{
			pop(stk,fp);
			pop(stk,sp);
			switch(j)
			{
				case 1 :	value = sp + fp;
							break;
				case 2 :	value = sp - fp;
							break;
				case 3 :	value = sp * fp;
							break;
				case 4 :	value = sp / fp;
							break;										
			}
		}
	}
}
