#include<bits/stdc++.h>

using namespace std;

unsigned long long m[500];
unsigned long long t[500];
unsigned long long male(int n)
{
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  if(m[n] == 0){
    m[n] = male(n-1) + male(n - 2) + 1;
    return m[n];
  }
  else{
    return m[n];
  }
}

unsigned long long total(int n)
{
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }

    if(t[n] == 0){
        t[n] = total(n - 1) + total(n - 2) + 1;
        return t[n];
    }
    else{
        return t[n];
    }
}
int main()
{
    int n;

    while(scanf("%d", &n) == 1 && n >= 0){
        printf("%llu %llu\n",male(n), male(n + 1));
    }

    return 0;
}
