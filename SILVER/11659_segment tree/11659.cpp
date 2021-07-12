#include <iostream>
using namespace std;

int N, M, n1, n2;
int arr[100005];
int sTree[400020];

int makeSTree(int left, int right, int node) {
	
	if (left == right) return sTree[node] = arr[left];

	int mid = left + right >> 1;

	return sTree[node] = makeSTree(left, mid, node * 2) + makeSTree(mid + 1, right, node * 2 + 1);

}

int getPartialSum(int start, int end, int node) {

	if (end < n1 || n2 < start) return 0;

	if (n1 <= start && end <= n2) return sTree[node];

	int mid = start + end >> 1;

	return getPartialSum(start, mid, node * 2) + getPartialSum(mid + 1, end, node * 2 + 1);

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	makeSTree(0, N - 1, 1);

	for (int i = 0; i < M; ++i) {
		cin >> n1 >> n2;
		n1 -= 1; n2 -= 1;
		cout << getPartialSum(0, N - 1, 1) << "\n";
	}

	return 0;
}
