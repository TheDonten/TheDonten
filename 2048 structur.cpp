#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 


void left(int matrix[4][4])
{
	 
	for (int i=0; i<4; i++)
	{
	 for (int i = 0; i<4; i++) {
	
		int n = 0;
		for (int j = 0; j < 4; j++) { 
		if (matrix[i][j] != 0) 
		{ 
		matrix[i][n] = matrix[i][j]; 
		if (n != j) matrix[i][j] = 0; n++;   
		} 
		                             }
		for (int j = 0; j<4; j++) 
		{ if ((matrix[i][j] == matrix[i][j + 1]) && (matrix[i][j] != 0)) 
		{ matrix[i][j] += matrix[i][j + 1]; matrix[i][j + 1] = 0; } }
		for
		 (int j = 0;j<3; j++) 
		 { if (matrix[i][j] == 0) { matrix[i][j] = matrix[i][j + 1]; matrix[i][j + 1] = 0; } }
		}
}
	}
	

 void printmatrix( int matrix [4][4])
 {
 
 for( int i=0; i<4; i++)
 {
 	for(int j=0; j<4; j++)
 	{
 		if( matrix[i][j] == 0)
 		{
 			cout<<'*'<< " ";
		 }
		 else cout << matrix[i][j] << " " ;
	 }
	 cout<<endl;
 }
 cout<<endl;
}


bool readmatrix( int matrix[4][4])
{
	bool success = true;
	for (int i = 0; i<4; i++)
	{
	string string;
	getline(cin,string);
	istringstream stream(string);
	for ( int j= 0; j<4; j++)
	  {
	 if(!(stream>> matrix[i][j])) {
	 success = false;
	 break;
      }
	}
}
	return success;
}

int main()
{
	int matrix[4][4];
	char op;
	if (readmatrix(matrix))
	while(cin>>op)
	{
		switch (op)
		{
			case 'h':{left(matrix); printmatrix(matrix); break;}
		}
	}
		printmatrix(matrix);
}
