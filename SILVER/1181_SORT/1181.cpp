#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Word {
private:
	string str;
	int size;
public:
	void GetElement(string str) {
		this->str = str;
		this->size = str.size();
	}
	bool operator<(const Word& ref) {
		if (size != ref.size)
			return size < ref.size;
		else {
			int min = this->size > ref.size ? this->size : ref.size, i=0;
      
      // 여기서 바로 this->str[i] < ref.str[i] return 걸면 정렬이 안됨.
      // break 걸고, 탈출 후에 return 걸어야됨..
			for (i = 0; i < min; ++i) {
				if (this->str[i] != ref.str[i])
					break;
			}
			return this->str[i] < ref.str[i];
		}

	}

	bool operator==(const Word& ref) {
		if (str == ref.str)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& ostm, const Word& ref);
};

ostream& operator<<(ostream& ostm, const Word& ref) {
	cout << ref.str << endl;
	return ostm;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	string str;

	Word* wArr = new Word[N];
	for (int i = 0; i < N; ++i) {
		cin >> str;
		wArr[i].GetElement(str);
	}
	sort(wArr, wArr + N);
	for (int i = 0; i < N-1; ++i) {
		if (wArr[i] == wArr[i + 1]) {
			continue;
		}
		else
			cout << wArr[i];
	}
	cout << wArr[N - 1];

	delete[]wArr;

	return 0;
}
