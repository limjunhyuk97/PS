#include <iostream>
using namespace std;

int grade[50];
int main(void){
	
	int N;
	cin >> N;
	int array[50][2];
	for(int i=0; i<N;++i){
		grade[i] = 1;
	}
	
	for(int i=0; i<N; ++i){
		cin>> array[i][0] >> array[i][1];
		for(int j=0; j<i; ++j){
			if(array[j][0]<array[i][0] && array[j][1]<array[i][1]){
				++grade[j];
			}
			else if(array[j][0]>array[i][0] && array[j][1]>array[i][1]){
				++grade[i];
			}
			else continue;
		}
	}
	
	for(int i=0; i<N ; ++i) printf("%d ",grade[i]);
	
	return 0;
}
