//Circular and single both used in the design and implementation of bitwise opeerators

#include <iostream>
#include <stdlib.h>

using namespace std;

class CDLL
{
	private :	int info;
				CDLL *left;
				CDLL *right;
	public  :	CDLL(){} //Null Constructor
				~CDLL (){}
	
	friend int length(CDLL *H);								
	friend int lengthR(CDLL *T);
	friend void print(CDLL *H);
	friend void printR(CDLL *T);
	friend void Addnode(CDLL *&H,CDLL *&T, int data);
	friend void Deleted(CDLL *&H,CDLL *&T, int data);
};

int length(CDLL *H)
{
	int numb(1); // int numb = 1; in C
	if(H == NULL)
	{
		return 0;
	}
	else
	{
		CDLL *T;
		T = H -> left;
		while(H != T)
		{
			++ numb;
			H = H -> right;
		}	
		return numb;
	}
} 

int lengthR(CDLL *T)
{
	int numb(1);
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		CDLL *H;
		H = T -> right;
		while(T != H)
		{
			++ numb;
			T = T -> left;
		}
		return numb;
	}
}

void print(CDLL *H)
{
	if(H == NULL)
	{
		cout << "NULL CDLL \n";
	}
	else
	{
		cout << "CDLL of length " << length(H) << " is \n";
		CDLL *T;
		T = H -> left;
		while(H != T)
		{
			cout << H -> info << "\n";
			H = H -> right;
		}
		cout << H -> info << "\n";
		cout << "... From Head to Tail \n"; 
	}
}

void printR(CDLL *T)
{
	if(T == NULL)
	{
		cout << "NULL CDLL \n";
	}
	else
	{
		cout << "CDLL of length " << length(T) << "\n" << " is \n";
		CDLL *H;
		H = T -> right;
		while (T != H)
		{
			cout << T -> info << "\n";
			T = T -> left;
		}
		cout << H -> info << "\n";
		cout << "... From Tail to Head \n";
	} 
}

void Addnode(CDLL *&H, CDLL *&T, int data)
{
	CDLL *temp = NULL;
	temp = new CDLL;
	if(temp == NULL)
	{
		exit(1);	
	}
	temp -> info = data;
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
	T -> right = H;
	H -> left = T;
}

void Deleted(CDLL *&H, CDLL *&T, int data)
{
	if(H == NULL)
	{
		return;
	}
	CDLL *curr;
	curr = H;
	while((curr != T) && (curr -> info != data))
	{
		curr = curr -> right;
	}
	if ((curr -> info != data))
	{
		return;
	}
	if(curr == H)
	{
		if(H == T)
		{
			H = T = NULL;
			H -> left = T;
			T -> right = H;
		}
		else if(curr == T)
		{
			T = curr -> left;
			H -> left = T;
			T -> right = H;
		}
	}
	else
	{
		(curr -> right) -> left = curr -> left;
		(curr -> left) -> right = curr -> right;
	}
	delete(curr);
}

int main()
{
	CDLL *Head = NULL;
	CDLL *Tail = NULL;
	
	int a[4] = {2,4,1,3},j;	
	
	print(Head);
	printR(Tail);
	
	for (j = 0; j < 4; j ++)
	{
		Addnode(Head,Tail,a[j]);
		print(Head);
		printR(Tail);	
	} 
}
