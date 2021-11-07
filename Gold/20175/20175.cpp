#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <limits>
using namespace std;
 
typedef long long int ll;
 
ll n, d, arr[1000005], min_val = 9e18, max_val = -9e18;
long double r1, r2;

int main(void) {
 
    cin >> n >> d;
    
    for (int i = 0; i < n; ++i)  cin >> arr[i];
    for(int i=0; i<n; ++i){
        if (arr[i] - (i * d) < min_val) {
            min_val = arr[i] - (i * d);
        }
        if (arr[i] - (i * d) > max_val) {
            max_val = arr[i] - (i * d);
        }
    }
    r1 = (long double)(max_val - min_val) / (long double)(2);
    
    min_val = 9e18; max_val = -9e18;
    for(int i=0; i<n; ++i){
        if (arr[i] + (i * d) < min_val) {
            min_val = arr[i] + (i * d);
        }
        if (arr[i] + (i * d) > max_val) {
            max_val = arr[i] + (i * d);
        }
    }
    r2 = (long double)(max_val - min_val) / (long double)(2);

    printf("%.1Lf\n", (r1 > r2 ? r2 : r1));
    
    return 0;
}
