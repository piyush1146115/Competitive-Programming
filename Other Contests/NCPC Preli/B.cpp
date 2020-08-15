#include<bits/stdc++.h>
using namespace std;



int main()
{
	string s;
	int date, test, cs = 0;
	
	scanf("%d", &test);
	
	while(test--){
		cin >> s >> date;
		
		printf("Case %d: ",++cs);
		
		if(s == "January")
		printf("Pohela Falgun\n");
		else if(s == "February"){
			if(date < 13)
			printf("Pohela Falgun\n");
			else if(date < 14)
			printf("Valentine's Day\n");
			else if(date < 21)
			printf("International Mother Language Day\n");
			else
			printf("International Women's Day\n");
		}
		else if(s == "March")
		{
			if(date < 8)
			printf("International Women's Day\n");
			else if(date < 21)
			printf("International Color Day\n");
			else if(date < 26)
			printf("Bangladesh Independence Day\n");
			else
			printf("April Fools Day\n");
		}
		
		else if(s == "April")
		{
			if(date < 14)
			printf("Pohela Boishakh\n");
			else
			printf("May Day\n");
		}
		else if(s == "May")
		{
			printf("Father's Day\n");
		}
		else if(s == "June"){
		if(date < 19)
		printf("Father's Day\n");
		else
		printf("Mandela Day\n");
		
		}
		
		else if(s == "July")
		{
			if(date < 18)
			printf("Mandela Day\n");
			else
			printf("World Mosquito Day\n");
		}
		else if(s == "August")
		{
			if(date < 20)
			printf("World Mosquito Day\n");
			else
			printf("Halloween\n");
		}
		else if(s == "September"){
		printf("Halloween\n");
		}
		else if(s == "October"){
		if(date < 31)
		printf("Halloween\n");
		else
		printf("World Toilet Day\n");
		}
		else if(s == "November")
		{
			if(date < 19)
			printf("World Toilet Day\n");
			else
			printf("Human Rights Day\n");
		}
		else if(s == "December")
		{
			if(date < 10)
			printf("Human Rights Day\n");
			else if(date < 16)
			printf("Victory Day of Bangladesh\n");
			else if(date < 25)
			printf("Christmas Day\n");
			else
			printf("Pohela Falgun\n");
			
	}
	
	}
	
	
}
