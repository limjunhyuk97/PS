#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	
	int arr[9] = {0, };
	int sum = 0;
	for(int i = 0 ; i < 9; ++i){
		cin>>arr[i];
	}
	sort(arr, arr+9);
	for(int i=0; i<9; ++i){
		for(int j=i+1; j<9; ++j){
			sum = 0;
			for(int k=0; k<9; ++k){
				if(k==i || k==j) continue;
				else sum+=arr[k];
			}
			if(sum == 100){
				for(int k=0; k<9; ++k){
					if(k==i || k==j) continue;
					else cout<< arr[k]<< endl;
				}
				break;
			}
		}
		if(sum == 100) break;
	}
	
	return 0;
}
