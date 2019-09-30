#include<bits/stdc++.h>
using namespace std;
int ar[20000];
int br[20000];
int k1,k2,n;
struct st{int dif,ind; };
vector<st>v;

bool cmp(st aa,st bb)
{
    if(aa.dif==bb.dif)
        return aa.ind<bb.ind;
    return aa.dif<bb.dif;
}
int main(){
   cin>>n;
   cin>>k1>>k2;
   for(int i=0;i<n;i++)
    cin>>ar[i];
   for(int i=0;i<n;i++)
    cin>>br[i];

   for(int i=0;i<n;i++)
   {
       st temp;
       temp.dif=abs(ar[i]-br[i]);
       temp.ind=i;
       v.push_back(temp);
   }
   sort(v.begin(),v.end(),cmp);
   int l=v.size();
   int total=k1+k2;
   while(total)
   {
       total--;
       if(l)
        {v[l-1].dif=abs(v[l-1].dif-1);
          sort(v.begin(),v.end(),cmp);
        }
   }
  long long int sum=0;
   for(int i=0;i<n;i++)
   {
       sum+=(long long int)(v[i].dif*v[i].dif);
   }
   cout<<sum<<endl;

}
