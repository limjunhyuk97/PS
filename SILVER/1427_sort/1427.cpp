#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int* arr, arrLen;
	
	cin >> str;
	arrLen = str.size();

	arr = new int[arrLen];
	for (int i = 0; i < arrLen; ++i) {
		arr[i] = str[i] - 48;
	}
	sort(arr, arr + arrLen, desc);
	for (int i = 0; i < arrLen; ++i) {
		cout<<arr[i];
	}

	delete[]arr;

	return 0;
}
