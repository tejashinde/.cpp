#include <iostream>
#include <stdlib.h>
/*
a. Node of a single linked list is connected to atmost one node 
b. Linearl Dowble Linked List represents a linear collection and enables movement in two directions through the linear collection.
*/
using namespace std;

class LDLL
{
	private :	int info;
				LDLL * left;
				LDLL * right;
	public :	LDLL(){}
				~LDLL(){}
	friend int length(LDLL *H); //FUNC - 1
	friend int lengthR(LDLL *T); //FUNC - 2
	friend void print(LDLL *H); //FUNC - 3					
	friend void printR(LDLL *T); //FUNC - 4
	friend void AddNode(LDLL *&H, LDLL *&T, int data); //FUNC - 5
	friend void deleted(LDLL *&H, LDLL *&T, int data); //FUNC - 6,
	friend bool Palindrome(LDLL *H, LDLL *T);
};
	
	//FUNC - 1
	int length(LDLL *H)
	{
		int numb(0); //int numb = 0; C syntax
		while (H != NULL)
		{
			++ numb;
			H = H -> right;
		}
		return (numb);
	}
	
	//FUNC - 2
	int lengthR(LDLL *T)
	{
		int numb(0);
		while(T != NULL)
		{
			++ numb;
			T = T-> left; 
		}
		return (numb);
	}
	
	//FUNC - 3
	void print(LDLL *H)
	{
		
		if(H == NULL)
		{
			cout << "NULL LDLL \n";
		}
		else
		{
			cout << "LDLL of length " << length(H) << " is : \n";
			while(H != NULL)
			{
				cout << H -> info << "\n";
				H = H -> right;
			}
		}
		cout << "...From head to tail \n";
	}
	
	//FUNC - 4
	void printR(LDLL *T)
	{
		if(T == NULL)
		{
			cout << "Null LDLL \n";
		}
		else
		{
			cout << "LDLL of length " << lengthR(T) << " is : \n";
			while(T != NULL)
			{
				cout << T -> info << "\n";
				T = T -> left;
			}
		}
		cout << "...From tail to head \n";
	}
	
	//FUNC - 5
	void AddNode(LDLL *&H, LDLL *&T, int data)
	{
		LDLL *temp;
		temp = new LDLL;
		if(temp == NULL)
		{
			exit(1);
		}
		temp -> info = data;
		temp -> left = NULL;
		temp -> right = NULL;
		if(H == NULL)
		{
			H = temp;	
		}
		else
		{
			T -> right = temp;
			temp -> left = T;
		}
		T = temp;
	}
	
	//FUNC - 6
	void deleted(LDLL *&H, LDLL *&T, int data)
	{
		LDLL *current;
		if(H == NULL)
		{
			return;
		}
		current = H;
		while((current != NULL) && current -> info != data)
		{
			current = current -> right;
		}
		if(current == NULL)
		{
			return;
		}
		if(current == H)
		{
			if(H == T)
			{
				H = T = NULL;
			}
			else
			{
				H = current -> right;
				H -> left = NULL;
			}
		}
		else if(current == T)
		{
			T = T -> left;
			T -> right = NULL;
		}
		else
		{
			current -> right -> left = current -> left;
			current -> left -> right = current -> right;
		}
		delete (current);
	}
	
	bool Palindrome(LDLL *H, LDLL *T)
	{
		if(H == NULL)
		{
			return(false);
		}
		while((H != T) && (H -> left != T))
		{
			if(H -> info != T -> info)
			{
				return(false);
			}
			H = H -> right;
			T = T -> left;
		}
		return(true);
	}
	
	// Main Function
	int main()
	{
		cout << "LDLL in C ++ \n";
		LDLL *Head = NULL;
		LDLL *Tail = NULL;
		int a[4] = {2,4,1,3},j;
		print (Head);
		
		for (j = 0 ; j < 4 ; ++ j)
		{
			AddNode(Head, Tail, a[j]);
			print(Head);
			printR(Tail);	
		}
		for (j = 0 ; j < 4 ; ++ j)
		{
			deleted(Head, Tail, a[j]);
			print(Head);
			printR(Tail);
			return 0;
		}
}
