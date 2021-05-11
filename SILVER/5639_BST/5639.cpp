#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	node* ln;
	node* rn;
	node* pn;
	int data;
};

node BSTRoot;
node* pNode, * cNode;
int n;

void makeNode(node* n, int d, node* l, node* r, node *p) {
	n = (node*)malloc(sizeof(node));
	n->data = d;
	n->ln = l;
	n->rn = r;
	n->pn = p;
}

bool insertNode(node* p, node* c, int d) {

	if (c == NULL) {
		makeNode(c, d, NULL, NULL, p);
		return true;
	}


	// 루트 노드에서 출발
	if (p == c) {
		if (c->data < d) {
			c = p->ln;
			insertNode(p, c, d);
		}
		else {
			c = p->rn;
			insertNode(p, c, d);
		}
	}

	// 새로 들어온 값 크다
	if (p->data < d) {

	}

	// 기존 값 크다.
	else {

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
	BSTRoot.data = n; BSTRoot.ln = BSTRoot.pn = BSTRoot.rn = NULL;
	pNode = cNode = &BSTRoot;
	
	while (!cin.eof()) {
		cin >> n;
		insertNode(pNode, cNode, n);
	}

	prostfixInorderTraverse(&BSTRoot);

	return 0;
}
