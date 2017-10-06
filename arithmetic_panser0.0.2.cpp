#include <iostream>

using namespace std;

int main()

{
	double x,y;
	char op, op1;

	cin >> x;
	cin.get(op1);

	while (op1 != '\n') 
	{
		cin.get(op);
		cin.get(op1);
		cin >> y;
		cin.get(op1);
	
		if(op == '+')
		     {
 	 		x = x+y;
		     }
	
		else if(op == '-')
		     {
  			x = x-y;
		     }

		else if(op == '*')
		     {
  			x = x*y;
		     }

		else if(op == '/') if (y==0) {cout << "infinite"; return 0;} 
			else x = x/y;
	 }
	
cout << x;
	
return 0;
}
