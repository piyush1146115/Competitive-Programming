/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1[100], n2[100], bin[100];
    long long int n, m,i, j, k, count ,ind1, ind2, sum;
    int a, b, c;
    while(scanf("%lld %lld", &n, &m) == 2){
        ind1 = 0;
        ind2 = 0;
        sum = 0;
        while(n >= 1){
            j = n % 2;
            n = n /2;
            n1[ind1++] = j;
        }

        while(m >= 1){
            j = m % 2;
            m = m /2;
            n2[ind2++] = j;
        }
        k = min(ind1, ind2);

        for(a = 0; a < k; a++){
            if(n1[a] + n2[a] == 1){
                bin[a] = 1;
            }
            else{
                bin[a] = 0;
            }
        }
        i = a;
     if(ind1 > ind2){
        for(i = a; i < ind1; i++){
            bin[i] = n1[i];
        }
     }
     else if(ind2 > ind1){
         for(i = a; i < ind2; i++){
            bin[i] = n2[i];
        }
     }
     b = 1;
     for(j = 0;j < i;j++){
        sum += (b * bin[j]);
        b *= 2;
     }

     printf("%lld\n",sum);
    }
    return 0;
}

*/
#include<bits/stdc++.h>
using namespace std;
#define r 1000
long long int arr1[r],arr2[r],arr[r],k,l,a;

void bin(long long int i)
{
    int k=-1;
    while(i!=0)
    {
        arr1[++k]=(i%2);
        i=i/2;
    }
//    a = k;
    return;
}

void bin2(long long int i)
{
    a=-1;
    while(i!=0)
    {
        arr2[++a]=(i%2);
        i=i/2;
    }

    return;
}

int main()
{
    long long int num1,num2,res,cas,i,j;
    while(scanf("%lld%lld",&num1,&num2)!=EOF)
    {

       memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr1));
        memset(arr,0,sizeof(arr1));


        bin(num1);
        bin2(num2);

        for(i=0; i<1000; i++)
        {
            j=arr1[i]+arr2[i];
            if(j%2==0)
            {
                arr[i]=0;
            }
            else
                arr[i]=1;
        }

	int sum = 0;
	int b = 1;

        for(i= 0; i < 100; i++)
        {
        sum += (b * arr[i]);
        b  *= 2;
         //   printf("%lld",arr[i]);
        }
        printf("%d\n", sum);
    }
    return 0;
}
