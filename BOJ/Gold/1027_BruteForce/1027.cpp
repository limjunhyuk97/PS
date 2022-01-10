#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#define IINF 2e9
#define LLINF 9e18
using namespace std;
typedef long long int ll;

int N;
int buildings[55];
int reach[55];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   for (int i = 0; i < N; ++i)
      cin >> buildings[i];

   for (int i = 0; i < N; ++i) {
       double tangent = IINF, cnt = 0;
       for(int j = i-1; j >=0 ; --j){
           if(tangent * (i - j) > (buildings[i] - buildings[j])){
               tangent = (buildings[i] - buildings[j])/(double)(i - j);
               ++cnt;
           }
       }
       tangent = -IINF;
       for(int j = i+1; j < N; ++j){
           if(tangent * (j - i) < (buildings[j] - buildings[i])){
               tangent = (buildings[j] - buildings[i])/(double)(j - i);
               ++cnt;
           }
       }
       reach[i] = cnt;
   }
   
    cout << *max_element(&reach[0], &reach[N]) << endl;

   return 0;
}
