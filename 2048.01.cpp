#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 


 void left(int matrix[4][4])
{
	 
	for (int i=0; i<4; i++)
	{
        int m = 0;
		for (int j = 0; j < 4; j++) 
		 { 
		        if (matrix[i][j] != 0) 
		        { 
		          matrix[i][m] = matrix[i][j]; 
		        if (m != j) matrix[i][j] = 0; m++;   
		        } 
		 }
	
		for (int j = 0; j<4; j++) 
		 { 
	         	if ((matrix[i][j] == matrix[i][j + 1]) && (matrix[i][j] != 0)) 
		        { 
				  matrix[i][j] += matrix[i][j + 1]; matrix[i][j + 1] = 0; 
				}
		 }
		
	    for (int j = 0;j<3; j++) 
		 { 
		        if (matrix[i][j] == 0) 
		
		        {
		          matrix[i][j] = matrix[i][j + 1]; matrix[i][j + 1] = 0; 
	            }
		 }
		
    }
}
 void right(int matrix[4][4])
{
	for (int i=0; i<4; i++)
	 {
	 	int m=3;
	 	for (int j =3; j >-1; j--)
	 	 {
		 
	 	        if( matrix[i][j] !=0)
	 	        {
	 	          matrix[i][m] = matrix[i][j];
	 	          if(m != j) matrix[i][j]= 0; m--;
				}
	     }
	 
	    for (int j=3; j >-1; j--)
         {  

	             if( (matrix [i][j] == matrix[i][j-1]) && (matrix[i][j] != 0))
	            {
	              matrix[i][j] += matrix[i][j-1]; matrix[i][j-1] = 0;
			    }
	     }
	    for (int j=3; j > 0; j--)
	     {
		 
	            if(matrix[i][j] == 0)
	            {
				  matrix[i][j] = matrix[i][j - 1]; matrix[i][j - 1] =0;
			    }
				
	     }
		
     }
}
 void up(int matrix[4][4])
{
	for (int i=0; i<4; i++)
	 {
	 	int m=0;
	 	for (int j =0; j < 4; j++)
	 	 {
		 
	 	         if( matrix[j][i] !=0)
	 	          {
	 	          	matrix[m][i] = matrix[j][i];
	 	          	if(m != j) matrix[j][i]= 0; m++;
				  }
	     }
	 
	    for (int j=0; j<4; j++)
         {  

	             if( (matrix [j][i] == matrix[j+1][i]) && (matrix[j][i] != 0))
	              {
	              	matrix[j][i] += matrix[j+1][i]; matrix[j+1][i] = 0;
				  }
	     }
	    for (int j=0; j < 3; j++)
	     {
		 
	            if(matrix[j][i] == 0)
	             {
				 matrix[j][i] = matrix[j+1][i]; matrix[j+1][i] =0;
	             }
				
		 }      
		
     }
}

 void down(int matrix[4][4])
{
	for (int i=0; i<4; i++)
	 {
	 	int m=3;
	 	for (int j =3; j > -1; j--)
	 	 {
		 
	 	         if( matrix[j][i] !=0)
	 	          {
	 	          	matrix[m][i] = matrix[j][i];
	 	          	if(m != j) matrix[j][i]= 0; m--;
				  }
	     }
	 
	    for (int j=3; j > -1; j--)
         {  

	             if( (matrix [j][i] == matrix[j-1][i]) && (matrix[j][i] != 0))
	              {
	              	matrix[j][i] += matrix[j-1][i]; matrix[j-1][i] = 0;
				  }
	     }
	    for (int j=3; j > -1; j--)
	     {
		 
	            if(matrix[j][i] == 0)
	              {
				   matrix[j][i] = matrix[j-1][i]; matrix[j-1][i] =0;
	              }
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
	 if(!(stream>> matrix[i][j])) 
	  {
	   success = false;
	   break;
      }
	}
}
	return success;
}

int main()
{   
    cout<<" Upravlenie h-vlevo, l-vpravo, k-verx, j-vniz, q-viyti iz igri "<<endl;
	int matrix[4][4];
	char op;
	if (readmatrix(matrix))
	while(cin>>op)
    {
		switch (op)
		{
			case 'h':{left(matrix); printmatrix(matrix); break;}
		    case 'l':{right(matrix); printmatrix(matrix); break;}
			case 'k':{up(matrix); printmatrix(matrix); break;}
			case 'j':{down(matrix); printmatrix(matrix); break;}
			case 'q':{cout<< "End" << endl; return -1; }
			default:{cout<< " Nepravelney simvol" <<endl; break;}
			
			
		}
	
    }
	else cout<< "Error"<<endl;
}
		
