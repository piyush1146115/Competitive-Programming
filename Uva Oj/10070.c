#include<stdio.h>
#include<stdbool.h>

bool isLeapYear(unsigned long long int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            return true;
        }
    else{
        return false;
    }
}

bool isHulukulu(unsigned long long int year){
    if(year % 15 == 0)
        return true;
    else
        return false;
}

bool isBulukulu(unsigned long long int year)
{

        if(year % 55 == 0 && isLeapYear(year) == true){
            return true;
        }

    else
        return false;

}

int main()
{

    unsigned long long int year;

    while((scanf("%llu", &year) != EOF))
        {

    if(isLeapYear(year))
        printf("This is leap year.\n");
    if(isHulukulu(year))
        printf("This is hulukulu festival year.\n");
    if(isBulukulu(year))
        printf("This is bulukulu festival year.\n");
    else if(!isLeapYear(year) && !isBulukulu(year) && !isHulukulu(year))
        printf("This is an ordinary year.\n");

    printf("\n");
    }
    return 0;
}
