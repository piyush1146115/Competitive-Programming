#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    map<char, int> m;
    set <char> st1, st2;
    string s1, s2;
    int test,i, j;

    while(scanf("%d",&test) == 1){
        if(test == -1)
            break;

            cin >> s1 >> s2;

        for(i = 0; i < s1.size(); i++){
            m[s1[i]]++;
            st1.insert(s1[i]);
        }

        for(i = 0; i < s2.size(); i++)
            st2.insert(s2[i]);
        set <char> :: iterator it;
        int cnt = 0, c = 0;
        for(it = st2.begin(); it != st2.end(); it++)
        {
            if(m[*it] == 0)
                cnt++;
            else
                c++;
        }
        printf("Round %d\n",test);
        if(c == st1.size() )
            printf("You win.\n");
        else if(c != st1.size() && cnt < 7)
            printf("You chickened out.\n");
        else
            printf("You lose.\n");

        st1.clear();
        st2.clear();
        m.clear();
    }
    return 0;
}
/*
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

int main ()
{
    int test;

    while (cin >> test) {

        if (test == -1)
        return 0;

        char solution [10000], guess [10000];
        cin >> solution;
        cin >> guess;
        int length = strlen (solution);
        list <char> l (&solution [0], &solution [length]);

        int flag = 0;
        length = strlen (guess);
        for (int i = 0; i < length; i++) {
            if (!l.empty()) {
                int size = l.size ();
                l.remove (guess [i]);
                if (size == l.size ())
                flag++;
            }
            else
            break;
        }

        if (l.empty () && flag < 7) {
            cout << "Round " << test << endl;
            cout << "You win." << endl;
        }
        else if (!l.empty () && flag < 7) {
            cout << "Round " << test << endl;
            cout << "You chickened out." << endl;
        }
        else {
            cout << "Round " << test << endl;
            cout << "You lose." << endl;
        }
    }

    return 0;
}*/
