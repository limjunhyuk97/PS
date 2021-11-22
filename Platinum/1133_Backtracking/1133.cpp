#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#define INF 1234567891
using namespace std;
typedef long long int ll;

int N, K, A, res_pos;
char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char res[55];

// promising check
bool promising(int len) {
	int max_partial = len / 2;
	int cnt = 0;
	// partial : 문자열 길이
	for (int partial = 1; partial <= max_partial; ++partial) {
		cnt = 0;
		pair<string, int> partial_string;
		// start : 문자열 시작점 지정
		for (int start = 0; start < partial; ++start) {
			// 중복 확인을 위한 과정
			int i = start, j = start + partial;
			while (j <= len) {
				string str;
				for (int k = i; k < j; ++k) str += res[k];
				if (i == start) {
					partial_string = { str, 1 };
					i = j; j = i + partial;
					continue;
				}
				if (partial_string.first == str) partial_string.second += 1;
				else partial_string = { str, 1 };
				if (partial_string.second == K) return false;
				i = j; j = i + partial;
 			}
		}
	}
	return true;
}

bool DFS(int n) {
	// promising check
	if (promising(n)) {
		// promising check - solution check
		if (n == N) return true;
		// promising check - DFS
		for (int i = 0; i < A; ++i) {
			res[res_pos++] = alpha[i];
			if (DFS(n + 1)) return true;
			res_pos -= 1;
		}
	}
	return false;
}

// N길이, K반복허용안함, A알파벳으로 구성
int main() {

	scanf("%d %d %d", &K, &N, &A);

	if (DFS(0)) {
		for (int i = 0; i < N; ++i) printf("%c", res[i]);
		printf("\n");
	}

	else printf("-1\n");

	return 0;
}
