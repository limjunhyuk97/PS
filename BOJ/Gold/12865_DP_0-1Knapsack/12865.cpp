#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, K;
int Knapsack[103][100005];
pair<int, int> L[105];

struct comp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.first != p2.first)
			return p1.first < p2.first;
		else
			return p1.second > p2.second;
	}
}comp;

int main(void) {

	cin >> N >> K;

	// first: 무게, second: 가치 
	for (int i = 1; i <= N; ++i) {
		cin >> L[i].first >> L[i].second;
	}

	sort(&L[1], &L[N+1], comp);

	for (int i = 1; i <= N; ++i) {
		for (int W = 1; W <= K; ++W) {
			if (L[i].first > W)
				Knapsack[i][W] = Knapsack[i - 1][W];
			else
				Knapsack[i][W] = max(Knapsack[i - 1][W - L[i].first] + L[i].second, Knapsack[i - 1][W]);
		}
	}

	cout << Knapsack[N][K] << '\n';

	return 0;
}
