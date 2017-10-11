#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{	
    double x, y, c;
    char op1, op2;
	
    string length;
    getline( cin, length );
    istringstream stream( length );

    stream >> x;
	
    while ( stream >> op1 ) {
    	stream >> y;

	if ( op1 == '+' ) {
    x += y;
	op2 = '+';
	c = y;
        }
		
        else if ( op1 == '-' ) {
	x -= y;
	op2 = '-';
	c = y;
        }
		
    	else if ( ( op1 == '*' ) && ( op2 == '*' ) ) {
       	    x *= y;
	}
		
    	else if ( ( op1 == '/' ) && ( op2 == '*' ) ) {
	    x /= y;
	}
		
    	else if ( (op1 == '*' ) && (op2 == '+' ) ) {
	    x -= c;
	    c *= y;
	    x += c;
	    op2 = '+';
	}
		
        else if ( ( op1 == '*' ) && ( op2 == '-' ) ) {
	    x += c;
	    c *= y;
	    x -= c;
	    op2 = '-';
	}
		
        else if ( ( op1 == '/' ) && ( op2 == '+' ) ) {
   	    x -= c;
	   c /= y;
	    x += c;
	    op2 = '+';
	}
		
        else if ( ( op1 == '/' ) && ( op2 == '-' ) ) {
	    x += c;
	    c /= y;
	    x -= c;
	    op2 = '+';
	}
		
        else {
	    cout << "Error";
	    cin.get();
	    return 0;
	}
    }	
  
    cout << x;
    cin.get();
    return 0;
}
