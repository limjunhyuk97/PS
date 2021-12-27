#include <stdio.h>
#include <math.h>
int decomposition(int n);
int levelFunction(int m);
int main(){
	
	int N, min = 0, ans = 0;
	
	scanf("%d", &N);
	
	min = N - levelFunction(N)*9;
	
	for(int i=min; i<=N; ++i){
		if(decomposition(i) == N){
			ans = i;
			break;
		}
	}
	if(ans != 0) printf("%d", ans);
	else printf("0");
	
	return 0;
}
int levelFunction(int m){
	int cnt = 0;
	while(1){
		++cnt;
		m /= 10;
		if(m == 0) break;
	}
	return cnt;
}
int decomposition(int n){
	int sum = n;
	while(1){
		sum+=n%10;
		n /= 10;
		if(n == 0) break;
	}
	return sum;
}
