#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
char ch[16];
vector<char> sequence;

void check(int num, int next) {

	if (num == 0) {
		int v = 0, c = 0;
		sort(sequence.begin(), sequence.end());
		for (int i = 0; i < L; ++i) {
			if (sequence[i] == 'a' || sequence[i] == 'e' || sequence[i] == 'i' || sequence[i] == 'o' || sequence[i] == 'u')
				v++;
			else
				c++;
		}
		if (v < 1 || c < 2)
			return;
		else {
			for (int i = 0; i < L; ++i)
				cout << sequence[i];
			cout << "\n";
			return;
		}
	}

	for (int i = next; i < C; ++i) {
		sequence.push_back(ch[i]);
		check(num - 1, i + 1);
		sequence.pop_back();
	}

}

int main(void) {

	cin >> L >> C;

	for (int i = 0; i < C; ++i) {
		cin >> ch[i];
	}

	sort(&ch[0], &ch[C]);
	check(L, 0);

	return 0;
}
