#include <iostream>
using namespace std;

long long arr[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };

int main(){
    
    for(int i=11; i<101; ++i){
        arr[i] = arr[i-1] + arr[i-5];
    }
    
    int T; cin>>T;
    for(int i = 0; i<T; ++i){
        int tmp; cin>>tmp;
        cout << arr[tmp]<<'\n';
    }
    
    return 0;
}