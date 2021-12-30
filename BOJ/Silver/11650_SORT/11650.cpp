#include <iostream>
#include <algorithm>
using namespace std;

class Point{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void PointInit(int x, int y) {
		xpos = x; ypos = y;
	}
	bool operator<(const Point &ref) {
		if (this->xpos != ref.xpos) return this->xpos < ref.xpos;
		else
			if (this->ypos != ref.ypos) return this->ypos < ref.ypos;
	}
	friend ostream& operator<<(ostream& ostm, const Point& ref);
};

ostream& operator<<(ostream& ostm, const Point& ref) {
	cout << ref.xpos << " " << ref.ypos << "\n";
	return ostm;
}

int main(void) {

	int N;
	cin >> N;
	
	Point* parr = new Point[N];

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		parr[i].PointInit(x, y);
	}
	sort(parr, parr + N);
	for (int i = 0; i < N; ++i) {
		cout << parr[i];
	}

	delete[]parr;

	return 0;
}
