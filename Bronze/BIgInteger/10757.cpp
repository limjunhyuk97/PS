// int형은 21억까지 표현가능하다. == 사실상 9자리이고, 최대 10자리까지 표현가능
// long은 922경까지 표현가능하다. == 사실상 18자리이고, 최대 19자리까지 표현가능

#include <iostream>
#include <string>
using namespace std;

class BigInteger {
private:
	string num;
	int* splitnum;
	int splitnumlen;
public:
	BigInteger(string num) : num(num) {
		MakeSplitnum();
	}

	void MakeSplitnum() {
		int rem = num.size() % 5;
		if (rem == 0) splitnumlen = (num.size() / 5);
		else splitnumlen = (num.size() / 5) + 1;

		splitnum = new int[splitnumlen] {};
		for (int i = 0; i < splitnumlen; ++i) {
			if (rem == 0) {
				splitnum[splitnumlen - i - 1] = stoi(num.substr(5 * i + rem, 5));
			}
			else {
				if (i == 0) {
					splitnum[splitnumlen - i - 1] = stoi(num.substr(0, rem));
				}
				else {
					splitnum[splitnumlen - i - 1] = stoi(num.substr(5 * (i - 1) + rem, 5));
				}
			}
		}
	}

	int OutSplitnumlen() const{
		return splitnumlen;
	}

	int* OutSplitnum() const {
		return splitnum;
	}

	~BigInteger() {
		delete[]splitnum;
	}
};

class BigIntegerOperator {
private:
	BigInteger &big1;
	BigInteger &big2;
public:
	BigIntegerOperator(BigInteger &big1, BigInteger &big2) : big1(big1), big2(big2) {}

	string AddBigInteger() {

		int maxsize = (big1.OutSplitnumlen() >= big2.OutSplitnumlen() ? big1.OutSplitnumlen() : big2.OutSplitnumlen());
		int* ansnum = new int[maxsize + 1]{};
		string ansstr;

		for (int i = 0; i < maxsize; ++i) {
			if (big1.OutSplitnumlen() <= i || big2.OutSplitnumlen()<=i) {
				if (big1.OutSplitnumlen() <= i && big2.OutSplitnumlen() <= i) continue;
				else if (big1.OutSplitnumlen() <= i) ansnum[maxsize - i - 1] += *(big2.OutSplitnum() + i);
				else if (big2.OutSplitnumlen() <= i) ansnum[maxsize - i - 1] += *(big1.OutSplitnum() + i);
			}
			else {
				if (*(big1.OutSplitnum() + i) + *(big2.OutSplitnum() + i) + ansnum[maxsize - 1 - i] > 100000) {
					ansnum[maxsize - 1 - i] += *(big1.OutSplitnum() + i) + *(big2.OutSplitnum() + i) - 100000;
					ansnum[maxsize - 1 - i - 1] += 1;
				}
				else {
					ansnum[maxsize - 1 - i] += *(big1.OutSplitnum() + i) + *(big2.OutSplitnum() + i);
				}
			}
		}
		
		for (int i = 0; i < maxsize; ++i) {
			string tmp = to_string(ansnum[i]);
			for (int i = 0; i < 5; ++i) {
				if (i < 5 - tmp.size()) ansstr.push_back('0');
				else {
					ansstr += tmp; break;
				}
			}
		}
		
		int cnt = 0;
		while (1) {
			if (ansstr[cnt] == '0')
				++cnt;
			else break;
		}

		return ansstr.substr(cnt);
	}

};

int main(void) {

	string str1, str2;
	cin >> str1 >> str2;

	BigInteger big1(str1);
	BigInteger big2(str2);
	BigIntegerOperator OP(big1, big2);
	cout<<OP.AddBigInteger();

	return 0;
}

// 이걸로 안풀림. 수정해야할 듯..
