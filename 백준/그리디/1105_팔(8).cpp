// L '이상' , R '이하' 의 조건이다..!
// 로직 : (자릿수 같은 경우)앞에서부터 비교하면서 같은 경우 - 8인경우 +1, - 아닌경우 계속 진행 / 달라진 경우 : 카운트 멈춘다. 무조건 8을 안쓸 수 있게 되기 때문에!
//     : (자릿수 다른 경우)자릿수가 다르면 그냥 무조건 8 안쓸 수 있다.

#include <iostream>
#include <string>
using namespace std;

int lenL, lenR, cnt;
string strL, strR;

int main(void){
    
    cin >> strL >> strR;
    lenL = (int)strL.size();
    lenR = (int)strR.size();
    
    if(lenL != lenR) cnt = 0;
    else
        for(int i=0; i<lenL; ++i){
            if(strL[i] == strR[i]){
                if(strL[i]=='8') cnt += 1;
                else continue;
            }
            else break;
        }
            
    printf("%d\n", cnt);
    
    return 0;
}
