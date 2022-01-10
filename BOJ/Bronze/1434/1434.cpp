#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
vector<int> boxCapacity;
bool boxCheck[53];

int main(void){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; ++i){
        int capacity; cin >> capacity;
        boxCapacity.push_back(capacity);
    }
    
    for(int i=0; i<M; ++i){
        int book; cin >> book;
        vector<int>::iterator iter = boxCapacity.begin();
        if(book <= boxCapacity[0]){
            boxCapacity[0] -= book;
            if(boxCapacity[0] == 0){
                boxCapacity.erase(iter);
            }
        }
        else{
            if(boxCapacity.size() >= 3 && book <= boxCapacity[2]){
                boxCapacity[2] -= book;
                if(boxCapacity[2] == 0){
                    boxCapacity.erase(iter + 2);
                }
            }
            else{
                boxCapacity[1] -= book;
                if(boxCapacity[1] == 0){
                    boxCapacity.erase(iter + 1);
                }
            }
        }
    }
    
    for(int i=0; i<boxCapacity.size(); ++i)
        T += boxCapacity[i];
    
    cout << T << "\n";
    
    return 0;
}
