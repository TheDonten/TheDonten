#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
int main ()
{
	int i, j=0;
	char a[80];
	for(i=0; i<80; i++){
		cin.get(a[i]);
		j++;
		if(a[i]=='\n'){
			break;
		}
	}
	for(i=0; i<=j; i++){
		if(a[i]==' '){
			cout<<"%20";
		}
		else{
			cout<<a[i];
		}
	}
return 0;
}
