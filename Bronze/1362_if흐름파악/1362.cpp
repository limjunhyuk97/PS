// 7

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long int ll;
string command = "#";
vector<string> result;
ll pw, cw, N, cnt = 1;

int main(void){
    
    while(command[0] - 48){
        
        cin >> pw >> cw;
        
        if(pw == 0 && cw == 0) break;
        
        while(true){
            cin >> command >> N;
            
            if(command == "0")
                break;
            
            if(command == "E"){
                if(cw > 0)
                    cw -= N;
            }
            else if(command == "F"){
                if(cw > 0)
                    cw += N;
            }
            else{
                if(cw <= 0) result.push_back(to_string(cnt++) + " " + "RIP");
                else if( (pw/2 < cw) && (cw < pw * 2) ) result.push_back(to_string(cnt++) + " " + ":-)");
                else result.push_back(to_string(cnt++) + " " + ":-(");
                break;
            }
        }
    }
    
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << "\n";
    
    return 0;
}
