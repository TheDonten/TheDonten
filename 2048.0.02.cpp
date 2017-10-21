#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
int n=0;

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
				  n += matrix[j][i];
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
	               n += matrix[j][i];
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
	              	 n += matrix[j][i];
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
	              	 n += matrix[j][i];
				  }
	     }
	    for (int j=3; j > 0; j--)
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
/* Проверка условия, что игрок может сделать ход: если существуют два соседних равных или хотя бы один
		нулевой элементы. В противном случае, программа выходит из цикла */
int proverka(int matrix[4][4]) 
{
	int l = false;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++)
			if (matrix[i][j] == matrix[i + 1][j] || matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == 0) {
				l = true;
				break;
			}
		if (l == true) break;
	}

	if (l != true) { cout << "No turns left. The End. Your result : " << n << endl; return -1; }
	return 0;
}


/* Ввод случайного значение (2 или 4) в случайнуюю ячейку матрицы */
	void generate_matrix(int matrix[4][4]) 
{
    int	i = rand() % 4;
	int j = rand() % 4;
	int	k = rand() % 10;
	if ((matrix[i][j] == 0) && (k == 1 ))
	{matrix[i][j] =4;}
	 else if (matrix[i][j] ==0 )
	 {matrix[i][j] = 2;}
	 else generate_matrix(matrix);
    
 
}
/*По условию задачи, необходимо, чтобы когда значение матрицы не менялось, ход не завершался, то есть не добавлялось новое число.
К примеру: 
           2 0 0 0
           2 0 0 0
           2 0 0 0
           2 0 0 0
Если мы сдвинем это влево, то ничего не поменяется, в таком случае нам нужно, чтобы новое число не добавлялось.
Именно для этого мы вводим доп. матрицу, в которое записывается значение основного поля перед сдвигом. 
Поэтому я ввожу функцию copy, которая и записывает основную матрицу, в доп.
*/
void copy(int matrix1[4][4], int matrix[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		matrix1[i][j] = matrix[i][j];
	}
}
/*Потом метод ravenstvo, который соответственно сравнивает любые две матрицы. В нашем случае основную и доп.
 В которое записывается значение главной матрицы перед сдвигом, таким образом мы сравниваем их и, если они равны, то новое число не добавляется.
*/

int ravenstvo(int matrix1[4][4], int matrix[4][4]) {
	int res = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			if (matrix1[i][j] != matrix[i][j]) return res = false;
			else res = true;
	}
	return res;
}

int main()
{   
    cout<<" Upravlenie h-vlevo, l-vpravo, k-verx, j-vniz, q-viyti iz igri "<<endl;
	int matrix[4][4]= { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	int matrix1[4][4]= { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	char op;
	srand(time(NULL));
	generate_matrix(matrix);
	generate_matrix(matrix);
	printmatrix(matrix);
	while(cin>>op)
    {  proverka(matrix);
		switch (op)
		{
			case 'h':{left(matrix);if (!(ravenstvo(matrix1, matrix))) { generate_matrix(matrix); } printmatrix(matrix); cout << "Your result: " << n << endl; break;}
		    case 'l':{right(matrix); if (!(ravenstvo(matrix1, matrix))) { generate_matrix(matrix); } printmatrix(matrix); cout << "Your result: " << n << endl; break;}
			case 'k':{up(matrix); if (!(ravenstvo(matrix1, matrix))) { generate_matrix(matrix); } printmatrix(matrix); cout << "Your result: " << n << endl; break;}
			case 'j':{down(matrix); if (!(ravenstvo(matrix1, matrix))) { generate_matrix(matrix); } printmatrix(matrix); cout << "Your result: " << n << endl; break;}
			case 'q':{cout<< "End, Your result: "<<n << endl; return -1; }
			default:{cout<< " Nepravelney simvol" <<endl; break;}
			
			
		}
	    copy(matrix1,matrix);
    }
	
}
