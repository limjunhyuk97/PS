#include <iostream>
#include <vector>
#define FOR(i, n, m) for(int i = n; i <= m; ++i)
using namespace std;

int N, input, tmp, lTmp, len, chunkCnt;
bool fFlag, pFlag;
vector<int> vArr;

int main(void) {

	cin >> N;

	FOR(i, 1, N) {
		cin >> input;
		vArr.push_back(input);

		if (i == 1) {
			lTmp = input;
			continue;
		}

		if (chunkCnt > 0 && (lTmp > input) && (tmp < input)) {
			pFlag = true;
			continue;
		}

		if (lTmp < input) {
			lTmp = input;
			chunkCnt = 0;
			continue;
		}
		else {
			tmp = input;
			chunkCnt = 1;
			continue;
		}

	}

	if (pFlag) {
		printf("NO");
	}
		
	else {
		lTmp = 0;
		tmp = 0;
		FOR(i, 0, N - 1) {
			input = vArr[i];
			if (input > tmp) {
				len = input - lTmp;
				FOR(j, 1, len) {
					printf("+\n");
				}
				lTmp = input;
				tmp = input;
			}
			else
				tmp = input;
			printf("-\n");
		}
	}

	return 0;
}
