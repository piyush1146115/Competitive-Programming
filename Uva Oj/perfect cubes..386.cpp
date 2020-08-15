#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007




int main()
{
    int qa,qb,qc,qd,qsum;

    for(int i=6;i<=200;i++)
    {
        qa= (int) pow((double) i, 3);
        for(int j=2;j<=200;j++)
        {
            qb= (int) pow((double) j, 3);
            for(int k=j+1;k<=200;k++)
            {
                qc= (int) pow((double) k, 3);
                for(int l=k+1;l<=200;l++)
                {
                    qd= (int) pow((double) l, 3);
                    qsum=qb+qc+qd;
                    if(qa == qsum)
                        cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
                }
            }
        }
    }

return 0;
}
