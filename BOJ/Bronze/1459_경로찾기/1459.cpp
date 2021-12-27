// 3
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll X, Y, W, S;

int main(void){
    
    cin >> X >> Y >> W >> S;
    
    if(W >= S){
        if( (max(X, Y) - min(X, Y)) % 2 ==0){
            cout << S * max(X, Y);
        }
        else{
            cout << S * (max(X, Y) - 1) + W;
        }
    }
    else if(W < S && S <= 2 *W){
        cout << S * min(X, Y) + W * (X - min(X, Y) + Y - min(X, Y));
    }
    else{
        cout << W  * (X + Y);
    }
    
    cout << "\n";
    
    return 0;
}
