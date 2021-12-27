#include <iostream>
#include <algorithm>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	
	void GetElement(int x, int y) {
		xpos = x; ypos = y;
	}

	bool operator<(const Point& ref) {
		if (ypos != ref.ypos)
			return ypos < ref.ypos;
		else
			if (xpos != ref.xpos)
				return xpos < ref.xpos;
	}

	friend ostream& operator<<(ostream& ostm, const Point& ref);

};

ostream& operator<<(ostream& ostm, const Point& ref) {
	cout << ref.xpos << " " << ref.ypos<<'\n';
	return ostm;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	Point* pArr = new Point[N];
	
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		pArr[i].GetElement(x, y);
	}
	sort(pArr, pArr + N);
	for (int i = 0; i < N; ++i) {
		cout << pArr[i];
	}

	delete[]pArr;

	return 0;
}
