#include <iostream>
using namespace std;
int main(void){
	
	char grid[50][50]; 
	int M, N;
	int min = 64, cnt_1 = 0, cnt_2 = 0;
	char flag_1, flag_2;
	
	cin >> M >> N;
	for(int i=0; i<M;++i){
		cin>>grid[i];
	}
	
	for(int i=0; i<M-7; ++i){
		for(int j=0; j<N-7; ++j){
			cnt_1 = 0;
			cnt_2 = 0;
			flag_1 = grid[i][j];
			if(flag_1 == 'W') flag_2 = 'B';
			else if(flag_1 == 'B') flag_2 = 'W';
			for(int k=i; k<8+i; ++k){
				for(int l=j; l<8+j; ++l){
					if(k%2 == i%2){
						if(l%2 == j%2){
							if(grid[k][l] != flag_1) ++cnt_1;
							if(grid[k][l] != flag_2) ++cnt_2;
						}
						else{
							if(grid[k][l] == flag_1) ++cnt_1;
							if(grid[k][l] == flag_2) ++cnt_2;
						}
					}
					else{
						if(l%2 == j%2){
							if(grid[k][l] == flag_1) ++cnt_1;
							if(grid[k][l] == flag_2) ++cnt_2;
						}
						else{
							if(grid[k][l] != flag_1) ++cnt_1;
							if(grid[k][l] != flag_2) ++cnt_2;
						}
					}
				}
			}
			if(min>cnt_1) min = cnt_1;
			if(min>cnt_2) min = cnt_2;
		}
	}
	cout << min;
	
	return 0;
}
