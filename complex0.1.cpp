#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct complex_t{
    float real;
    float imag; 
};

bool read(istringstream & stream,complex_t & n)
{
    
	char simvol, simvol2, simvol3;
	bool res =true;
    if(stream>>simvol)
   {
     if(simvol=='(')
       {
       	if(stream>>n.real)
       	  {
		    if(stream>>simvol2)
		    {
		     if(simvol2 ==',')
		       {
		       	if(stream>>n.imag)
		       	   {
		       	   	if(stream>>simvol3)
		       	   	   {
		       	   	   	if(simvol3 == ')')
					     {
					       {return true;}
						 }
						    else
                            {res= false;cout<<"An error has occured while reading input data";}
				       }
					      else
                          {res= false;cout<<"An error has occured while reading input data";} 
				   }
				      else
                      {res= false;cout<<"An error has occured while reading input data";}
			   }
			      else
                  {res= false;cout<<"An error has occured while reading input data";}
			}
			  else
             {res= false;cout<<"An error has occured while reading input data";}
	      }
          else
          {res= false;cout<<"An error has occured while reading input data";}
       }
        else
        {res= false;cout<<"An error has occured while reading input data";}
   }
    else
    {  res= false;cout<<"An error has occured while reading input data";
	 }
}
    void write(ostream &stream, complex_t complex) {
    (stream << '(' << complex.real << ',' << complex.imag << ')' << endl);
    
}
   complex_t add(complex_t m1, complex_t m2) 
    {
    complex_t complex;
    complex.real = m1.real + m2.real;
    complex.imag = m1.imag + m2.imag;
    return complex;
    }
    complex_t sub(complex_t m1, complex_t m2) 
    {
    complex_t complex;
    complex.real = m1.real - m2.real;
    complex.imag = m1.imag - m2.imag;
    return complex;
    }
    complex_t mul(complex_t m1, complex_t m2) 
    {
    complex_t complex;
    complex.real = m1.real * m2.real - m1.imag * m2.imag;
    complex.imag = m1.imag * m2.real + m1.real * m2.imag;
    return complex;
    }

    complex_t div(complex_t m1, complex_t m2) 
    {
    complex_t complex;
    complex.real = (m1.real * m2.real + m1.imag * m2.imag)/(m2.real * m2.real + m2.imag * m2.imag);
    complex.imag = (m1.imag * m2.real - m1.real * m2.imag)/(m2.real * m2.real + m2.imag * m2.imag);
    return complex;
    }
int main()
{
	complex_t m1,m2,res;
	char op;
	string string;
	getline(cin, string);
	istringstream stream(string);
	if(read(stream,m1))
	{
	   if(stream>>op)
	   {
	     if(read(stream,m2))
	      {
		   switch(op)
		    {
		    	case '+': {res = add(m1,m2);break;};
		    	case '-': {res = sub(m1,m2);break;};
				case '*': {res = mul(m1,m2);break;};
				case '/': {res = div(m1,m2);break;};
			    default:{cout<<"Nepravilnya operacia"<<endl;break;};
					
			
		    }
		     write(cout,res);
		  }
	   }
	  
	} 
}
