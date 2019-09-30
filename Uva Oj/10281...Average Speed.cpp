#include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    double h[1000], m[1000], s[1000], dis = 0, speed, hDif, mDif, sDif;
    int i, a = 0, b = 0, c = 0, len, count = 0;

    while(gets(str)){
        len = strlen(str);

        if(len >= 9){
                 count++;

            h[a++] = (str[1] - 48) + (10.0 * (str[0] - 48));
            m[b++] = (str[4] - 48) + (10.0 * (str[3] - 48));
            s[c++] = (str[7] - 48) + (10.0 * (str[6] - 48));
            if(count > 1){
                hDif = h[a - 1] - h[a - 2];
                mDif = m[b - 1] - m[c - 2];
                sDif = s[c - 1] - s[c - 2];

                dis += (hDif * speed) + ((mDif/ 60.0) * speed) + ((sDif/3600.0) * speed);
            }

            i = 9;
            speed = 0;
            while(i < len){
                if(str[i] >= '0' && str[i] <= '9')
                    speed = (str[i] - 48) +  speed * 10.0;
                i++;
            }


        }
        else{
             h[a++] = (str[1] - 48) + (10.0 * (str[0] - 48));
            m[b++] = (str[4] - 48) + (10.0 * (str[3] - 48));
            s[c++] = (str[7] - 48) + (10.0 * (str[6] - 48));

                hDif = h[a -1] - h[a - 2];
                mDif = m[b - 1] - m[b - 2];
                sDif = s[c - 1] - s[c - 2];

                dis += (hDif * speed) + ((mDif/ 60.0) * speed) + ((sDif/3600.0) * speed);

            //printf("%f %f %f %d\n",hDif,mDif, sDif, k);
            printf("%s %.2lf km\n",str, dis);
        }
    }
    return 0;
}
