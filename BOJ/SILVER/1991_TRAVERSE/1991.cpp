#include <iostream>
#define FOR(i ,n) for(int i = 0; i < (n) ; ++i)
using namespace std;

typedef struct BTreeNode {
	char data;
	struct BTreeNode* lSub;
	struct BTreeNode* rSub;
}btNode;

int N;
char subTreeData[26][2];
char root, sub1, sub2;
btNode* btArr[26];

void PreorderTraverse(btNode *bt) {
	if (bt == NULL) return;
	cout << bt->data;
	PreorderTraverse(bt->lSub);
	PreorderTraverse(bt->rSub);
}

void InorderTraverse(btNode *bt) {
	if (bt == NULL) return;
	InorderTraverse(bt->lSub);
	cout << bt->data;
	InorderTraverse(bt->rSub);
}

void PostorderTraverse(btNode *bt) {
	if (bt == NULL) return;
	PostorderTraverse(bt->lSub);
	PostorderTraverse(bt->rSub);
	cout << bt->data;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;
	FOR(i, N) {
		cin >> root >> sub1 >> sub2;
		btNode* newNode = new btNode;
		newNode->data = root; newNode->lSub = NULL; newNode->rSub = NULL;
		btArr[root - 65] = newNode;
		subTreeData[root - 65][0] = sub1;
		subTreeData[root - 65][1] = sub2;
	}

	FOR(i, N) {
		if (subTreeData[i][0] != '.') btArr[i]->lSub = btArr[subTreeData[i][0] - 65];
		if (subTreeData[i][1] != '.') btArr[i]->rSub = btArr[subTreeData[i][1] - 65];
	}

	PreorderTraverse(btArr[0]); cout << '\n';
	InorderTraverse(btArr[0]); cout << '\n';
	PostorderTraverse(btArr[0]); cout << '\n';

	return 0;
}
