#include <iostream>
#define MAX 10
using namespace std;

int N, M;
int arr[MAX];
bool trace[MAX];

void Sequence(int num) {
	if (num == M+1) {
		for (int i = 1; i <= M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (!trace[i]) {
			trace[i] = true;
			arr[num] = i;
			Sequence(num+1);
			trace[i] = false;
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	cin >> N >> M;
	Sequence(1);

	return 0;
}
