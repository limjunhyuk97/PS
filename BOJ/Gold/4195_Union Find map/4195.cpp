#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
using namespace std;

typedef map<string , pair<string ,int> > profile;

struct Set {
	
	profile parent;

	string Find(string name) {
		
		string root = name;
		if (!parent.count(name)) parent[name] = make_pair(name, 1);

		for (; parent[root].first != root; root = parent[root].first);

		while (root != name) {
			string tmp = parent[name].first;
			parent[name].first = root;
			name = tmp;
		}

		return root;
	}

	void Union(string name1, string name2) {
		
		string root1 = Find(name1);
		string root2 = Find(name2);
		int tmp = parent[root1].second + parent[root2].second;

		if (root1 != root2) {
			if (parent[root1].second > parent[root2].second) {
				parent[root2].first = root1;
				parent[root1].second = tmp;
			}
			else {
				parent[root1].first = root2;
				parent[root2].second = tmp;
			}
		}

	}

};

int T, N;
string p1, p2;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;

		Set set;
		while (N--) {
			cin >> p1 >> p2;
			set.Union(p1, p2);
			cout << set.parent[set.Find(p1)].second << "\n";
		}
	}


	return 0;
}
