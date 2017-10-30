#include<iostream>
#include <sstream>
using namespace std;

char print_pole(char   array[3][3])
{

cout<<"    1   2   3"<<endl;
cout<<"  +---+---+---+"<<endl;
for (int i=0; i<3; i++)
{
	for(int j=0; j<3; j++)
	{    
	   
		if(i==0 && j==0)
		{
		  cout<<"a | "<<array[0][0]<<" | ";
		}
	    if(i==0 && j==1)
	    {
	      cout<<array[0][1]<<" | ";
		}
		if(i==0 && j==2)
		{
		  cout<<array[0][2]<<" |"<<endl;
		  cout<<"  +---+---+---+"<<endl;
		}
	    if(i==1 && j==0)
	    {
	      cout<<"b | "<<array[1][0]<<" | ";
	   
	     
		}
		if(i==1 && j==1)
	    {
	      cout<<array[1][1]<<" | ";
	    
	     
		}
		if(i==1 && j==2)
	    {
	      cout<<array[1][2]<<" |"<<endl;
	      cout<<"  +---+---+---+"<<endl;
	     
		}
	    if(i==2 && j==0)
	    {
	      cout<<"c | "<<array[2][0]<<" | ";
		}
	    if(i==2 && j==1)
	    {
	      cout<<array[2][1]<<" | ";
		}
	    if(i==2 && j==2)
	    {
	      cout<<array[2][2]<<" |"<<endl;	
		}
	}  
 
}
cout<<"  +---+---+---+"<<endl;
}
bool proverka(char array[3][3]){
	 int k=0;
	for ( int i=0; i<3; i++){
		for(int j=0;j<3;j++){
		
		if (!(array[i][j]=='X' || array[i][j]=='O'))
		{
			k++;
		}
		if (k>0) return true;
    
	}
	}
	return false;
}


int main()
{
char op,op1,op2;
char  array[3][3]={0,0,0,0,0,0,0,0,0};
print_pole(array);
cout<<"1. mark cell a1 as X"<<endl;
cout<<"2. mark cell a2 as X"<<endl;
cout<<"3. mark cell a3 as X"<<endl;
cout<<"4. mark cell b1 as X"<<endl;
cout<<"5. mark cell b2 as X"<<endl;
cout<<"6. mark cell b3 as X"<<endl;
cout<<"7. mark cell c1 as X"<<endl;
cout<<"8. mark cell c2 as X"<<endl;
cout<<"9. mark cell c3 as X"<<endl;



while(cin>>op)
{ 
switch(op)
{
	
case '1':{if(array[0][0]=='O')
{ cout<<" ";}
else array[0][0]=' X';print_pole(array);break;}
case '2':{array[0][1]=' X';print_pole(array);break;}
case '3':{array[0][2]=' X';print_pole(array);break;}
case '4':{array[1][0]=' X';print_pole(array);break;}
case '5':{array[1][1]=' X';print_pole(array);break;}
case '6':{array[1][2]=' X';print_pole(array);break;}
case '7':{array[2][0]=' X';print_pole(array);break;}
case '8':{array[2][1]=' X';print_pole(array);break;}
case '9':{array[2][2]=' X';print_pole(array);break;}
}

 
	 
 
 while(cin>>op1)
 {  
 switch(op1)
   {
     case '1':{array[0][0]=' O';print_pole(array);break;}
     case '2':{array[0][1]=' O';print_pole(array);break;}
     case '3':{array[0][2]=' O';print_pole(array);break;}
     case '4':{array[1][0]=' O';print_pole(array);break;}
     case '5':{array[1][1]=' O';print_pole(array);break;}
     case '6':{array[1][2]=' O';print_pole(array);break;}
     case '7':{array[2][0]=' O';print_pole(array);break;}
     case '8':{array[2][1]=' O';print_pole(array);break;}
     case '9':{array[2][2]=' O';print_pole(array);break;}
   }
   if(array[0][0]==0)
  { 
   cout<<"1. mark cell a1 as X"<<endl;
  }   
if(array[0][1]==0)
  { 
   cout<<"2. mark cell a2 as X"<<endl;
  }   
if(array[0][2]==0)
  { 
   cout<<"3. mark cell a3 as X"<<endl;
  }   
if(array[1][0]==0)
  { 
   cout<<"4. mark cell b1 as X"<<endl;
  }   
if(array[1][1]==0)
  { 
   cout<<"5. mark cell b2 as X"<<endl;
  }   
if(array[1][2]==0)
  { 
   cout<<"6. mark cell b3 as X"<<endl;
  }   
if(array[2][0]==0)
  { 
   cout<<"7. mark cell c1 as X"<<endl;
  }   
if(array[2][1]==0)
  { 
   cout<<"8. mark cell c2 as X"<<endl;
  }   
if(array[2][2]==0)
  { 
   cout<<"9. mark cell c3 as X"<<endl;
  }   
  break;
 }
}


}





