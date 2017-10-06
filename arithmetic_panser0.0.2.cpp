#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
int main ()
{
string length;
double x,y;
char op1;

getline( cin, length);
istringstream stream(length);

stream>>x;
while ( stream>>op1)
 {
    if( op1=='+')
    {
        stream>>y;
        x += y;
    }
    if( op1=='-')
    {
        stream>>y;
        x -= y;
    }
    if (op1=='*')
    {
        stream>>y;
        x *= y;
    }
    if(op1=='/')
    {
        if (x==0 && y==0) {cout<<"nan";}
        else if (x!=0 && y==0) {cout<<"inf";}
        else 
        stream>>y;
        x /= y;
    }
    
 }
 cout<<x;
}
