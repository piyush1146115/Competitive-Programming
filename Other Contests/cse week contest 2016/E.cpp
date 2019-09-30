#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
  //  while(scanf("%d",&n) == 1){
    if(n == 9)
     {
     //    int m = n - 9;
         printf("72\n");
     }
     else if(n > 9){
        string s = "72";
        while(n > 9){
            s += "0";
        n--;
     }
     cout << s << endl;
//     s.clear();

     }
    else{
        printf("0\n");
    }
     return 0;
}

