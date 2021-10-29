#include <iostream>
using namespace std;

int m, s, x1, x2;

int main(void){
    
    cin >> m >> s >> x1 >> x2;
    int a = 1, c = 0;
    
    if(s == x1){
        cout << x1 / s << " " << x1 % s << endl;
    }
    else{
        while(1){
            for(c=0; c<m; ++c){
                if( (c + s * a) % m == x1 && (c + a * x1) % m == x2 ){
                    cout << a << " " << c << endl;
                    return 0;
                }
            }
            ++a;
        }
    }
    
    return 0;
}
