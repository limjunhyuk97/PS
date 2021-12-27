// 3
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, GroupCount;

int WhoIsNasty(int left, int total, int start){
    if(start + left < total)
        return start + left;
    else
        return (start + left) % total;
}

int main(void){
    
    while(true){
        ++GroupCount;
        
        cin >> N;
        if(N == 0) break;
        
        vector<string> circle;
        vector<pair<string, int> > nastyList;
        for(int i=0; i<N; ++i){
            string name; cin >> name; circle.push_back(name);
            for(int j=0; j<N-1; ++j){
                string nasty; cin >> nasty;
                if(nasty == "N")
                    nastyList.push_back({name, WhoIsNasty(N-j-1, N, i)});
            }
        }
        
        cout << "Group " << GroupCount << "\n";
        if(nastyList.empty()){
            cout << "Nobody was nasty\n\n";
        }
        else{
            for(int i=0; i<nastyList.size(); ++i){
                cout << circle[nastyList[i].second] << " was nasty about " << nastyList[i].first << "\n";
            }
            cout << "\n";
        }
        
    }
    
    return 0;
}
