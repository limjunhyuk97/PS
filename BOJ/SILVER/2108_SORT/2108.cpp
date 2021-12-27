#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FLAG 5000
using namespace std;

int modeArr[8001], mode[2] = { FLAG, FLAG }, modeCnt = 0;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, sum = 0, ave = 0;
	int min = 4000, max = -4000;
	cin >> N;

	int* arr = new int[N];
	
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		sum += arr[i];
		++modeArr[arr[i] + 4000];
		if (min >= arr[i])
			min = arr[i];
		if (max <= arr[i])
			max = arr[i];
	}

	sort(arr, arr + N);

	ave = round(sum / (double)N);
	for (int i = 8000; i >=0; --i) {
		if (modeArr[i] == 0)
			continue;
		if (modeArr[i] < modeCnt)
			continue;
		else if(modeArr[i] == modeCnt){
			mode[0] = mode[1];
			mode[1] = i - 4000;
		}
		else {
			modeCnt = modeArr[i];
			mode[0] = mode[1] = i-4000;
		}
	}

	// 산술평균
	cout << ave << '\n';
	// 중앙값
	cout << arr[N / 2] << '\n';
	// 최빈값
	if (mode[0] == FLAG)
		cout << mode[1] << '\n';
	else
		cout << mode[0] << '\n';
	// 범위
	cout << max - min << '\n';

	delete[]arr;

	return 0;
}
