#include <iostream>
#include <vector>
using namespace std;

int N, t;
vector<int> tree;
int two, one;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; ++i){
        cin>>t;
        tree.push_back(t);
    }
    
    for(int i=0; i<tree.size(); ++i){
        one += tree[i] % 2;
        two += tree[i] / 2;
    }
    
    if(one > two) cout<<"NO\n";
    else{
        if( (two - one) % 3 == 0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}
