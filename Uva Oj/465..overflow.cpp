#include<bits/stdc++.h>
using namespace std;
int main()
{
   string a, b;
   char ch;
   int i, j, k;

   while(cin >> a >> ch >> b){
    int f1 =1, f2 = 1;
    unsigned long long n1 = 0, n2 = 0;

    for(i = 0; i < a.size(); i++){
        n1 = (a[i] - 48) + n1 * 10;
    }

      for(i = 0; i < b.size(); i++){
        n2 = (b[i] - 48) + n2 * 10;
      }
            cout << a << " " << ch << " " <<b << endl;

     if(n1 >2147483647 ){
        printf("first number too big\n");
    }
    if(n2 > 2147483647)
         printf("second number too big\n");

    if(ch == '+' && n1 + n2 > 2147483647 )
        printf("result too big\n");
         else if(ch == '*' && (n1 * n2) > 2147483647)
      printf("result too big\n");
      a.clear();
      b.clear();
   }
   return 0;
}
