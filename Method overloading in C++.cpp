#include <iostream>

using namespace std;

int absolute (int n){
	cout << "Using int abs(int)";
	return(n<0?-n:n);
}
float absolute (float n){
	cout << "Using float abs(float)";
	return(n<0.0?-n:n);
}

int main(){
	int *a;
	a = new int[3];
	a[0] = 1;
	cout << *a;
	cout << "Function overloading \n";
	int x = 10;
	int y = 5.6;
	
	cout << x << " " << absolute(x) << " " << "\n";
	cout << y << " " << absolute(y);	
	return 0;
}
