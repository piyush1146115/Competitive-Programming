#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, e, a, b, i, j, l, cont, mx, test = 0, ara[25];
    string temp, excuse[25], key[25], COPY[25];

    while(scanf("%d %d",&k, &e) == 2)
    {
        mx = -132332;
        for(i = 0; i < k; i++)
            cin >> key[i];
        getchar();
        for(i = 0; i < e; i++)
            getline(cin, excuse[i]);

        for(i = 0; i < e; i++)
        {
            COPY[i] = excuse[i];
            for(j = 0; j < excuse[i].size(); j++)
            {
                if(excuse[i][j] >= 65 && excuse[i][j] <= 90)
                {
                    excuse[i][j] += 32;
                }
            }
        }

        for(i = 0; i < e; i++)
        {
            cont = 0;
            for(j = 0; j < excuse[i].size(); j++)
            {
                l = 0;
                temp.clear();
                while(isalpha(excuse[i][j]))
                {
                    temp.push_back(excuse[i][j]);
                    j++;
                    if(j == excuse[i].size())
                        break;
                }
                //temp[l] = '\0';
                for(a = 0; a < k; a++)
                {
                    //cout << temp <<"  "<< key[a] << endl;
                    if(key[a] == temp)
                    {
                        cont++;
                        break;
                    }
                }
            }
            if(cont > mx)
                mx = cont;
            ara[i] = cont;
        }

        printf("Excuse Set #%d\n",++test );

        for(i = 0; i < e; i++)
        {
            if(ara[i] == mx)
            {
                cout << COPY[i] << endl;
            }
        }

        cout << endl;
    }
    return 0;
}
