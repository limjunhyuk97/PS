#include <iostream>
using namespace std;

string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(void){
	
	int date, month, num=0;
	cin>>month>>date;
	
	for(int i=1; i<=month; ++i){
		if(i!=month){
			if(i==1 || i==3|| i==5||i==7||i==8||i==10||i==12) num+=31;
			else if(i ==4 || i==6 || i==9||i==11) num +=30;
			else if(i==2) num+=28;
		}
		else{
			num += date;
			break;
		}
	}
	
	--num;
	num = num % 7;
	if(num<=5 && num>=0) cout<<day[num+1];
	else cout<<day[0];
	
	return 0;
}
