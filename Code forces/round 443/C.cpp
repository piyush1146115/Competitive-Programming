//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define pb push_back
//#define mp make_pair
//#define pii pair<int, int>
//#define pll pair<ll, ll>
//#define DEBUG(x) cout<<#x<<": "<<x<<endl
//
//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//    pair<char, int> pp [10];
//
//    int orr= 0, xorr = 0, andd = 0;
//    getchar();
//    for(int i = 0; i < n; i++){
//      char ch;
//      int k;
//
//      scanf("%c %d",&ch, &k);
//      getchar();
////      DEBUG(k);
////      DEBUG(ch);
//    if(n <= 5){
//        pp[i] = mp(ch, k);
//    }
//    if(ch == '^'){
//        xorr |= k;
//    }
//    else if(ch == '|'){
//        orr |= k;
//    }
//    else{
//        andd |= k;
//    }
//
//    }
//    //DEBUG(test);
//    if(n <= 5){
//        printf("%d\n",n);
//        for(int i = 0; i < n; i++)
//            printf("%c %d\n",pp[i].first, pp[i].second);
//    }
//    else{
//    printf("3\n");
//    printf("| %d\n",orr);
//    printf("^ %d\n",xorr);
//    printf("& %d\n",andd);
//    }
//}

#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie();
bool Check(int num,int pos) { return (bool)(num&(1<<pos)); }
int Set(int num,int pos) { return (num|(1<<pos)); }

int n;
const int N = 500005;
string str[N];
int val[N];
bool bit[N][12];

int main()
{
   FastRead
   cin >> n;
   REP(i,n)cin >> str[i] >> val[i];

   REP(i,n)REP(j,10)bit[i][j] = Check(val[i],j);

   int OR = 0 , AND = 0, XOR = 0, ANTI = 0;

   for(int j = 0;j < 10;j++){
      bool in = false;
      REP(i,n){
         if(str[i] == "&")in = in and bit[i][j];
         else if(str[i] == "|")in = in or bit[i][j];
         else in = in xor bit[i][j];
      }
      bool out1 = in;

      in = true;
      REP(i,n){
         if(str[i] == "&")in = in and bit[i][j];
         else if(str[i] == "|")in = in or bit[i][j];
         else in = in xor bit[i][j];
      }
      bool out2 = in;
      if(out1 == true and out2 == true){
         OR = OR | (1 << j);
         AND = AND | (1 << j);
      }
      else if(out1 == true and out2 == false){
         XOR = XOR | (1 << j);
         AND = AND | (1 << j);
      }
      else if(out1 == false and out2 == false ){

      }else{
         AND = AND | (1 << j);
      }

   }

   cout << 3 << "\n";
   cout << "& " << AND << "\n";
   cout << "| " << OR << "\n";
   cout << "^ " << XOR << "\n";


}
