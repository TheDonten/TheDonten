#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    for( string string;getline(cin, string ); ) {
        int a[ 10 ];
        istringstream stream( string );
        bool failure = false;
        for( int i = 0; i < 10; ++i ) {
            if( !( stream >> a[ i ] ) ) {
                failure = true;
                break;
            }
        }
         
        if( !failure ) {
            int max=a[0];
            for( int i = 0; i < 10; ++i )
            {  
                if(max < a[i]) 
                {max = a [i];}
            } 
                 cout << "Max : " << max;
            
        }
        else {
           cout << "An error has occured while reading numbers from line";
           break;
        }
cin.get();
   return 0;
    }
   
}
