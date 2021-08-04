// 3

#include <iostream>
#include <string>
#include <map>
using namespace std;

string input, Month;
int Day, Year, Hour, Minute, TotDay, TotSecond, CurSecond;

// map 초기화의 방식
map<string, int> NameOfMonth = { {"January" , 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12} };
map<int, int> DayOfMonth ={{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

int DayOfYear(int year){
    if(year % 400 == 0) return 366;
    else if(year % 100 == 0) return 365;
    else if(year % 4 == 0) return 366;
    else return 365;
}

int main(void){
    
    // 문자열 파싱 : find(delimiter, 시작 인덱스(따로 부여하지 않으면 0 부터 시작))
    getline(cin, input);
    int cur = 0; int next = (unsigned int)input.find(" ");
    Month = input.substr(cur, next);
    cur = next + 1; next = (unsigned int)input.find(", ", cur);
    Day = stoi(input.substr(cur, next));
    cur = next + 2; next = (unsigned int)input.find(" ", cur);
    Year = stoi(input.substr(cur, next));
    cur = next + 1; next = (unsigned int)input.find(":", cur);
    Hour = stoi(input.substr(cur, next));
    cur = next + 1;
    Minute = stoi(input.substr(cur, input.size() - 1));
    
    TotDay = DayOfYear(Year);
    TotSecond = TotDay * 24 * 60 * 60;
    
    for(int i = 1; i < NameOfMonth[Month]; ++i){
        if(i == 2 && TotDay == 366) CurSecond += (29 * 24 * 60 * 60);
        else CurSecond += (DayOfMonth[i] * 24 * 60 * 60);
    }
    
    CurSecond += ((Day - 1) * 24 * 60 * 60);
    CurSecond += Hour * 60 * 60;
    CurSecond += Minute * 60;
    
    cout << fixed;
    cout.precision(15);
    cout << (double)CurSecond / (double)TotSecond * (double)100;
    
    return 0;
}
