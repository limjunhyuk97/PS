#include <iostream>
#include <algorithm>
using namespace std;

int maximum (int left, int right, int arr[]){
    if(left >= right) return arr[left];
    int mid = left + right >> 1;
    return max(maximum(left, mid, arr) , maximum(mid+1, right, arr));
}

int Index_location (int left, int right, int K, int arr[]){
    
    if(left > right) return 0;

    int len = right - left + 1;
    int p1 = left + (int)(len/3);
    int p2 = p1 + (int)(len/3);

    if(K < arr[p1]) return Index_location(left, p1-1, K, arr);
    else if(K == arr[p1]) return p1;
    else if(arr[p1] < K && K < arr[p2]) return Index_location(p1+1, p2-1, K, arr);
    else if(K == arr[p2]) return p2;
    else return Index_location(p2+1, right, K, arr);
}


int main(void){
    
    int arr[21] = {3, 10, 22, 5000, 1, 6003, 65, 234, 5, 6, 3, 76, 1, 3, 45, 666, 70, 2345, 4, 65, 89};
    
    cout << maximum(0, 2, arr) << endl;
    
    sort(&arr[0], &arr[21]);
    
    for(int i=0; i<21; ++i){
        cout << i << ") " << arr[i] << endl;
    }
    
    cout << Index_location(0, 20, 4, arr) << endl;
    
    return 0;
}
