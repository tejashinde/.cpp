#include <iostream>
#include <stdlib.h>

using namespace std;
class CSLL
{
	private :	int info;
				CSLL *next;
	public  :	CSLL(){}// Null constructor
				~CSLL(){}
	friend int length (CSLL *H, CSLL *T); //FUNC - 1
	friend void print (CSLL *H, CSLL *T); //FUNC - 2
	friend void addNode (CSLL *&H,CSLL *&T,int data);//FUNC - 3
	friend void deleteNode (CSLL *&H,CSLL *&T,int data);//FUNC - 4			 							
};// End of class

//FUNC - 1
int length (CSLL *H, CSLL *T){
	int numb = 1;
	if (H == NULL)
	{
		return 0;
	}
	else
	{
		while(H!=T)
		{
			++ numb;
			H = H->next;
		}
		return (numb);
	}
}

//FUNC - 2
void print (CSLL *H, CSLL *T)
{
	if(H == NULL)
	{
		cout << "NULL CSLL\n";	
	}
	else
	{
		cout << "CSLL of length " << length(H,T);
		cout << " is : \n";
		while  (H!=T)
		{
			cout << H -> info << "\n"; 
			H = H -> next;
		}
		cout << H -> info << "\n";		
	}
}

//FUNC - 3
void addNode (CSLL *&H,CSLL *&T,int data)
{
	CSLL *temp;
	temp = new CSLL;
	if(temp == NULL)
	{
		exit(1);
	}
	temp -> info = data;
	if(H==NULL)
	{
		H = temp;	
	}
	else
	{
		T -> next = temp;
	}
	T = temp;
	T -> next = H; 	
}

//FUNC - 4
void deleteNode (CSLL *&H,CSLL *&T,int data)
{
	if(H == NULL)
	{
		return;	
	}		
	
	CSLL *curr,*ref;
	curr = H;
	ref = NULL;
	
	while((curr != T) && (curr -> info != data))
	{
		ref = curr;
		curr = curr -> next;
	}
	if(curr -> info != data)
	{
		return;
	}
	if(curr == H)
	{
		if(H == T)
		{
			H = T = NULL;
		}
		else
		{
			H = curr -> next;
			T -> next = H; 
		}
	}
	else if(curr == T)
	{
		T = ref;
		T -> next = H;
	}
	else 
	{
		ref -> next = curr -> next;
	}
	
	delete(curr);
}

//MAIN FUNCTION
int main()
{
	cout << "CSLL in C++ \n";
	CSLL *head = NULL;
	CSLL *tail = NULL;
	int a[4] = {2,1,4,3},j;
	print(head,tail);
	for(j = 0 ; j < 4 ; j ++)
	{
		addNode(head,tail,a[j]);
		print (head,tail);
	}
	for (j = 0 ; j < 4 ; ++ j)
	{
		deleteNode(head,tail,a[j]);
		print(head,tail);
	}
	return 0;
}
