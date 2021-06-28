// quadratic probing 이용 시도 -> 시간 초과

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	string type;
	int cnt;
};

int T, N, H, Cnt, A, choicePoint[37];
string name;
node choice[37];

void quadraticInsert(int H, string name) {

	node *newNode = new node{ name, 1 };

	if (choice[H].type == "") {
		choice[H] = *newNode;
		choicePoint[Cnt++] = H;
		return;
	}
	else {
		if (choice[H].type == name) {
			choice[H].cnt++;
			return;
		}
		for (int i = 1; i <= 18; ++i) {
			if (choice[H + i * i].type == "") {
				choice[H + i * i] = *newNode;
				choicePoint[Cnt++] = H + i * i;
				return;
			}
			else if (choice[H + i * i].type == name) {
				choice[H + i * i].cnt++;
				return;
			}
			if (choice[H - i * i].type == "") {
				choice[H - i * i] = *newNode;
				choicePoint[Cnt++] = H - i * i;
				return;
			}
			else if (choice[H - i * i].type == name) {
				choice[H - i * i].cnt++;
				return;
			}
		}
	}

}

int Combination(int n, int start) {
	if (n == 0)
		return 1;

	int ret = 0;

	for (int i = start; i < Cnt; ++i) {
		ret += choice[choicePoint[i]].cnt * Combination(n - 1, i + 1);
	}

	return ret;
}

int main(void) {

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		// 종류 추가 완료
		Cnt = 0;
		for (int j = 0; j < N; ++j) {
			
			cin >> name >> name;

			H = name[0] % 37;
			quadraticInsert(H, name);

		}

		// 종류에 대한 연산
		A = 0;
		for (int j = 0; j < Cnt; ++j) {
			A += choice[choicePoint[j]].cnt;
		}
		for (int j = 2; j <= Cnt; ++j) {
			A += Combination(j, 0);
		}

		cout << A << "\n";

	}



	return 0;
}
