#include<stdio.h>
 /*long double fact[52] = {0};
 long double factorial(int n)
{
    if(n == 0){
        return 1;
    }
    int a;
    long double s=1;
    if(fact[n] == 0){
        for(a = 1; a <= n; a++){
            s = s * a;
        }
        fact[n] = s;
    }
    return fact[n];
}
 unsigned long long int combination(int n, int r)
{
    unsigned  long long result;
    result=(factorial(n))/(factorial(n - r) * factorial(r));
    return result;
}

int main()
{
  unsigned long long a, b, i, j, sum;
  int n;
  while(scanf("%llu",&n) == 1 && n!= 0){
  i = n/2;
  sum = 0;
  for(a = 1; a<=i;a++){
    sum = sum + combination(n-a, a);
  }
  sum++;
  printf("%llu\n",sum);
  }
  return 0;
}
*/
int main()
{
unsigned long long b,p;
while(scanf("%llu",&b)==1)
{
if(b==0) break;
unsigned long long  x=0,y=1,p=0;
int i;
for(i=1;i<=b;i++)
{
p=x+y;
x=y;
y=p;
}
printf("%llu\n",p);
}
return 0;
}
