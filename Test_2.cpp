#include <iostream>
#include <sstream>
using namespace std;

int main (){
	string stroka;
	int a[10]; int i, j; int r=0;
	getline(cin, stroka);
	istringstream stream(stroka);
	for(i=0; i<10; ++i){
	    if(!(stream>>a[i])){
	        cout<<"An error has occurred while reading the input sequence."<<endl;
	        return -1;
	    }
	    if(r>a[i]){
	        cout<<"The input sequence must be non-decreasing."<<endl;
	        return -1;
	    }
	    r=a[i];
	}
	int b;
	cin>>b;
	for(i=0; i<10; ++i){
	    for(j=0; j<10; ++j){
	        if((a[i]+a[j])==b){
	            cout<<a[i]<<" "<<a[j];
	            return 0;
	        }
	    }
	}
	cout<<"There is no such pair of numbers."<<endl;
	return -1;
}
