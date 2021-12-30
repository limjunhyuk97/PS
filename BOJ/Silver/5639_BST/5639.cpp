#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	node* ln;
	node* rn;
	int data;
};

node BSTRoot;
node* pNode, * cNode;
int n;

node makeNode(int d, node* l, node* r) {
	node tmp = { l, r, d };
	return tmp;
}

bool insertNode(node* p, node* c, int d, bool direction) {

	// 루트 노드에서 출발
	if (p == c) {
		if (p->data < d) {
			c = p->rn;
			if (insertNode(p, c, d, false))
				return true;
		}
		else {
			c = p->ln;
			if (insertNode(p, c, d, true))
				return true;
		}
	}

	if (c == NULL) {
		c = (node *)malloc(sizeof(node)); 
		*c = makeNode(d, NULL, NULL);
		if (direction) p->ln = c;
		else p->rn = c;
		return true;
	}

	// 새로 들어온 값 크다
	if (c->data < d) {
		p = c;
		c = p->rn;
		if(insertNode(p, c, d, false))
			return true;
	}

	// 기존 값 크다.
	else {
		p = c;
		c = p->ln;
		if (insertNode(p, c, d, true))
			return true;
	}
}

void prostfixInorderTraverse(node* p) {
	if (p == NULL) {
		return;
	}

	prostfixInorderTraverse(p->ln);
	prostfixInorderTraverse(p->rn);
	cout << p->data << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	BSTRoot.data = n; BSTRoot.ln = BSTRoot.rn = NULL;
	
	while (!cin.eof()) {
		cin >> n;
		insertNode(&BSTRoot, &BSTRoot, n, true);
	}

	prostfixInorderTraverse(&BSTRoot);

	return 0;
}
