#include <iostream>
#define MAX 10
using namespace std;

int N, M;
int arr[MAX];

// start, end는 1 ~ n
void Sequence(int start, int end, int num) {
	if (num == M+1) {
		for (int i = 1; i <= M; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	else {
		for (int i = start; i <= end; ++i) {
			arr[num] = i;
			Sequence(i + 1, end, num + 1);
		}
	}

}

int main(void) {

	cin >> N >> M;
	
	Sequence(1, N, 1);

	return 0;
}
