#include <iostream>

using namespace std;

int main(){
    const int n = 1499;
    int a [ 1500 ];
    int p1(0), p2(0), p3(0), end(0);
    a [ 0 ] = 1;
    while ( end < n ){
        while ( a [ p1 ] * 2 <= a [ end ] )  ++ p1;
        while ( a [ p2 ] * 3 <= a [ end ] )  ++ p2;
        while ( a [ p3 ] * 5 <= a [ end ] )  ++ p3;
        if ( a [ p1 ] * 2 < a [ p2 ] * 3 && a [ p1 ] * 2 < a [ p3 ] * 5 )
            a [ ++ end ] = a [ p1 ++ ] * 2;
        else    if ( a [ p2 ] * 3 < a [ p3 ] * 5 )
                    a [ ++ end ] = a [ p2 ++ ] * 3;
                else    a [ ++ end ] = a [ p3 ++ ] * 5;
    }
    cout << "The 1500'th ugly number is " << a [ end ] << ".\n";
    return 0;
}
