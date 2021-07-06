#include <iostream>
using namespace std;

int N, cnt;
int inorder[100005];
int postorder[100005];
int preorder[100005];

void findPreorder(int inleft, int inright, int postleft, int postright) {
	
	if (inleft == inright) { preorder[cnt++] = inorder[inleft]; return; }

	for (int i = inleft; i <= inright; ++i) {
		if (inorder[i] == postorder[postright]) {
			preorder[cnt++] = postorder[postright];
			findPreorder(inleft, i - 1, postleft, postleft + (i - inleft - 1));
			findPreorder(i + 1, inright, postright - 1 - (inright - i - 1), postright - 1);
			return;
		}
	}

}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> inorder[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> postorder[i];
	}

	findPreorder(0, N-1, 0, N-1);

	for (int i = 0; i < N; ++i)
		cout << preorder[i] << " ";
	cout << "\n";

	return 0;
}
