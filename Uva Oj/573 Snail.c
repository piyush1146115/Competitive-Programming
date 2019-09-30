#include<stdio.h>
int main()
{
    int height, climb , slide, fatigue, Dis_cli, he_af_cli, ini_he, he_af_sl,fati_fac;
    scanf("%d %d %d %d", &height ,&climb,&slide,&fatigue);
    fati_fac=(fatigue/100)*climb;
    Dis_cli=climb;
    while(he_af_cli>0 && he_af_cli<height)
    {
        ini_he=he_af_sl;
        he_af_cli=ini_he+Dis_cli;
        he_af_sl=he_af_cli - slide;
        Dis_cli = Dis_cli - fati_fac;
    }
    if(he_af_cli <=0){printf("failed"); }
    else{printf("succeed");}

}
