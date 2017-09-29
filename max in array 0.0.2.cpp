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
   
   if( read_numbers( array1 ) && read_numbers( array2 ) )
   {    int max1=array1[0];
        int max2=array2[0];
       for( int i = 0; i < 10; ++i ) {
           if(max1 < array1[i])
           {max1=array1[i];}
           if(max2 < array2[i])
           {max2 = array2[i];}
   }
   int res=max1+max2;
   cout << " "<<res;}
   else {
           cout << "An error has occured while reading numbers from line";
           
        }
   }
