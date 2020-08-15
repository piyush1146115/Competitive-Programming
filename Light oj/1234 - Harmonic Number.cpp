    #include<bits/stdc++.h>
    using namespace std;
    #define gama 0.57721566490
     
    double h[1000005];
     
    void harmonic()
    {
        double sum = 0.0;
        for(int i = 1; i <= 1000001; i++){
            sum += 1.0/(double)i;
            h[i] = sum;
        }
    }
     
    int main()
    {
        harmonic();
       
        int test, cs = 0;
       
        scanf("%d", &test);
       
        while(test--){
            long long n;
        scanf("%lld" ,&n);
        printf("Case %d: ",++cs);
       
        if(n <= 1000000){
        printf("%.12lf\n",h[n]);
        }
        else{
            double x = n + 0.5;
            double ans = gama + log(x);
           
            printf("%.12lf\n",ans);
        }
    }
    return 0;
    }
     
