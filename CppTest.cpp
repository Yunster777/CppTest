// CppTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;

// 함수 정의
void PairNTuple();
void Substring_Test();
void MakeVector();
void MakeArray();
void ReverseStr();

int main()
{
	//Substring_Test();
    //PairNTuple();
	//MakeVector();
	//MakeArray();
	ReverseStr();

    return 0;
}

void ReverseStr() {
	string name;
	string reverse_name = "";

	cin >> name;

	int size = name.size();
	for (int i = size - 1; i >= 0; i--) {
		reverse_name += name.substr(i, 1);
	}

	cout << reverse_name << "\n";
}

void MakeArray() {
	int arr[10];

	for (int i = 1; i <= 10; i++) arr[i - 1] = i;
	for (int a : arr) cout << a << " ";
	cout << "\n";

	auto a = find(arr, arr + 10, 11);
	if (a == arr + 10) cout << "not found" << "\n";
	else cout << "Found!!" << "\n";

	fill(arr, arr + 10, 10);
	for (int a : arr) cout << a << " ";
	cout << "\n";
}

void MakeVector() {
	vector<int> v;
	for (int i = 1; i <= 10; i++) v.push_back(i);
	for (int a : v) cout << a << " ";
	cout << "\n";
	v.pop_back();

	for (int a : v) cout << a << " ";
	cout << "\n";

	v.erase(v.begin(), v.begin() + 1);

	for (int a : v) cout << a << " ";
	cout << "\n";

	auto a = find(v.begin(), v.end(), 10);
	if (a == v.end()) cout << "Not found.." << "\n";
	else cout << "Found!!" << "\n";

	fill(v.begin(), v.end(), 10);
	for (int a : v) cout << a << " ";
	cout << "\n";
}

void PairNTuple() {
	pair<int, int> pi;
	tuple<int, int, int> tl;
	int a, b, c;

	pi = { 1, 2 };
	tl = make_tuple(1, 2, 3);
	tie(a, b) = pi;
	cout << a << " : " << b << "\n";
	tie(a, b, c) = tl;
	cout << a << " : " << b << " : " << c << "\n";
}

void Substring_Test() {
	string dopa = "life is limited";

	cout << dopa << "\n";
	cout << dopa.substr(0, 3) << "\n";
	reverse(dopa.begin(), dopa.end());
	cout << dopa << "\n";
}

