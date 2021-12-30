#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Person {
private:
	int age, turn;
	string name;
public:
	void GetElement(int age, int turn, string name) {
		this->age = age;
		this->name = name;
		this->turn = turn;
	}
	bool operator< (const Person& ref) {
		if (age != ref.age) {
			return age < ref.age;
		}
		else {
			if (turn != ref.turn)
				return turn < ref.turn;
		}
	}
	friend ostream& operator<<(ostream& ostm, const Person& ref);
};

ostream& operator<<(ostream& ostm, const Person& ref) {
	cout << ref.age << " " << ref.name << '\n';
	return ostm;
}

int main(void) {

	int N; cin >> N;
	Person* pArr = new Person[N];

	for (int i = 0; i < N; ++i) {
		int age; cin >> age;
		string str; cin >> str;
		pArr[i].GetElement(age, i, str);
	}
	sort(pArr, pArr + N);
	for (int i = 0; i < N; ++i) {
		cout << pArr[i];
	}

	delete[]pArr;

	return 0;
}
