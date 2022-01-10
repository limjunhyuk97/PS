#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int cnt;
	int* arr;

	cin >> cnt;
	arr = new int[cnt];
	for (int i = 0; i < cnt; ++i) cin >> arr[i];
	sort(arr, arr + cnt);
	for (int i = 0; i < cnt; ++i) cout << arr[i] << '\n';
	delete[]arr;

	return 0;
}
