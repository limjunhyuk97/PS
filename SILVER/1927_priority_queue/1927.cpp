// priority queue를 직접 구현한다.

#include <iostream>
using namespace std;

int N, T;
int minHeap[100006], cnt;

int getChildIdx(int heap[], int n) {
	if (n * 2 > cnt) return 0;
	else if (n * 2 == cnt) return cnt;
	else return (heap[n * 2] > heap[n * 2 + 1] ? 2*n+1 : 2*n);
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> T;
		if (T == 0) {
			if (cnt == 0) {
				cout << 0 << '\n';
				continue;
			}
			else {

				cout << minHeap[1] << '\n';

				int lastVal = minHeap[cnt--];
				int parent = 1;
				int child = getChildIdx(minHeap, parent);

				while ((child > 0) && (minHeap[child] < lastVal)) {
					minHeap[parent] = minHeap[child];
					parent = child;
					child = getChildIdx(minHeap, parent);
				}

				minHeap[parent] = lastVal;

				continue;

			}
		}
		else {
			if (cnt == 0) {
				minHeap[++cnt] = T;
				continue;
			}
			else {

				int child = ++cnt;
				int parent = child / 2;

				while ((parent >= 1) && (minHeap[parent] > T)) {
					minHeap[child] = minHeap[parent];
					child = parent;
					parent = child / 2;
				}

				minHeap[child] = T;

				continue;
			}
		}

	}

	return 0;
}
