// 숫자 string 변환 사용됨
// 반례 party...

#include <iostream>
#include <string>
using namespace std;

int N, grid[65][65];
string line, ans;

string QuadTree(int ulx, int uly, int len) {

	if (len == 1)
		return to_string(grid[ulx][uly]);

	len /= 2;
	string portion[2][2];
	portion[0][0] = QuadTree(ulx , uly, len);
	portion[0][1] = QuadTree(ulx , uly + len, len);
	portion[1][0] = QuadTree(ulx + len, uly, len);
	portion[1][1] = QuadTree(ulx + len, uly + len, len);

	if ((portion[0][0] == "0" || portion[0][0] == "1") && portion[0][0] == portion[0][1] && portion[0][0] == portion[1][0] && portion[0][0] == portion[1][1])
		return portion[0][0];

	return "(" + portion[0][0] + portion[0][1] + portion[1][0] + portion[1][1] + ")";

}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> line;
		for (int j = 0; j < N; ++j) {
			grid[i][j] = line[j] - 48;
		}
	}

	ans = QuadTree(0, 0, N);
	cout << ans;

	return 0;
}
