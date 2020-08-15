#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> s1, s2;
    string n1, n2;
    int i, j, n, k;

    while(getline(cin, n1)){
        getline(cin, n2);
        istringstream ss(n1);

        while(ss >> n)
            s1.insert(n);

        istringstream is(n2);

        while(is >> n)
            s2.insert(n);

        int c1 = 0, c2 = 0;

        set <int>:: iterator it;

        for(it = s1.begin(); it != s1.end(); it++){
            if(s2.find(*it) != s2.end())
                c1++;
        }


        for(it = s2.begin(); it != s2.end(); it++){
            if(s1.find(*it) != s1.end())
                c2++;
        }
        //cout << c1 << " " << c2 << endl;

        if(c1 == s1.size() && s1.size() == s2.size()){
            printf("A equals B\n");
        }
        else if(s1.size() > s2.size() && c2 == s2.size())
            printf("B is a proper subset of A\n");

        else if(s2.size() > s1.size() && c1 == s1.size())
            printf("A is a proper subset of B\n");
       else  if(c1 == 0 && c2 == 0)
            printf("A and B are disjoint\n");
        else
            printf("I'm confused!\n");

            s1.clear();
            s2.clear();
    }
    return 0;
}
