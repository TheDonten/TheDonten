#include <iostream>
#include <sstream>
using namespace std ;

bool read_numbers(int array[10])
{
    string string; 
    getline( cin, string );
    istringstream stream( string );
    bool success = true;
    for( int i = 0; i < 10; ++i ) {
        if( !( stream >> array[ i ] ) ) {
           success = false;
           break;
        }
    }
   
   return success;
}

int main()
{
   int array1[10];
   int array2[10];
   int max=0;
   
 
   if( read_numbers( array1 ) && read_numbers( array2 ) ) 
   {
       for (int i=0; i<10; ++i)
       {
           
          for (int k=i; k<10; ++k) 
          {
              
                if (max < array1[i]+array2[k]) max = array1[i]+array2[k];
          }
       }
       cout << max;
   }
   else {
       std::cout << "An error has occurred while reading numbers";
   }
}
