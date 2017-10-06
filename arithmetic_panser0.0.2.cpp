#include <iostream>

using namespace std;

int main()

{
	double a,b;
	char op, op1;

	cin >> a;
	cin.get(op1);

	while (op1 != '\n') 
	{
		cin.get(op);
		cin.get(op1);
		cin >> b;
		cin.get(op1);
	
		if(op == '+'){
 	 		a = a+b;
		}
	
		else if(op == '-'){
  			a = a-b;
		     }

		else if(op == '*'){
  			a = a*b;
		     }

		else if(op == '/') if (b==0) {cout << "You can`t use 0"; return 0;} 
			else a = a/b;
	 }
	
cout << a;
	
return 0;
}
