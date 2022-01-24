// CppTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// 함수 정의
void PairNTuple();
void Substring_Test();
void MakeVector();
void MakeArray();
void ReverseStr();
void MakeMap();
void MakeSet();
void MakeMultiSet();
void MakeStack();
void MakeQueue();
void MakeDeque();
void MakePriorityQueue();
void MakePriorityQueue2();
void MakePriorityQueue3();

int main()
{
	//Substring_Test();
    //PairNTuple();
	//MakeVector();
	//MakeArray();
	//ReverseStr();
	//MakeMap();
	//MakeSet();
	//MakeMultiSet();
	//MakeStack();
	//MakeQueue();
	//MakeDeque();
	//MakePriorityQueue();
	//MakePriorityQueue2();
	MakePriorityQueue3();

    return 0;
}

void MakePriorityQueue3() {
	// 우선순위 queue 커스텀 정렬
	struct Point
	{
		int y, x;
	};

	struct cmp {
		bool operator() (Point a, Point b) {
			return a.x < b.x;
		}
	};

	priority_queue<Point, vector<Point>, cmp> pq;

	pq.push({ 1, 1 });
	pq.push({ 2, 2 });
	pq.push({ 3, 3 });
	pq.push({ 4, 4 });
	pq.push({ 5, 5 });
	pq.push({ 6, 6 });

	cout << pq.top().x << "\n";
}

void MakePriorityQueue2() {
	// 우선순위 queue에 다른 자료구조 넣기
	struct Point
	{
		int y, x;
		Point(int y, int x) : y(y), x(x) {}
		Point() { y = -1; x = -1; }
		bool operator < (const Point& a) const {
			return x < a.x;
		}
	};

	priority_queue<Point> pq;

	pq.push({ 1, 1 });
	pq.push({ 2, 2 });
	pq.push({ 3, 3 });
	pq.push({ 4, 4 });
	pq.push({ 5, 5 });
	pq.push({ 6, 6 });

	cout << pq.top().x << "\n";
}

void MakePriorityQueue() {
	// 우선순위 queue. 내부 구조는 heap으로 구현되어 있으며, 주로 다익스트라, 그리디 등에 사용
	// greater : 오름차순, less : 내림차순
	//priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
	priority_queue<int, vector<int>, less<int>> pq; // 내림차순

	pq.push(5);
	pq.push(4);
	pq.push(3);
	pq.push(2);
	pq.push(1);

	cout << pq.top() << "\n";
}

void MakeDeque() {
	// Deque : queue랑 비슷하지만 앞/뒤로 넣고 뺄 수 있음
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);

	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n";

	dq.pop_back();
	dq.pop_front();

	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n";

}

void MakeQueue() {
	// FIFO
	queue<int> q;
	
	q.push(1);
	cout << q.front() << "\n";

	q.pop();
	cout << q.size() << "\n";
}

void MakeStack() {
	// LIFO
	stack<string> stk;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stk.push("엄");
	stk.push("준");
	stk.push("식");
	stk.push("화");
	stk.push("이");
	stk.push("팅");

	while (stk.size()) {
		cout << stk.top() << "\n";
		stk.pop();
	}
}

void MakeMultiSet() {
	// 중복되는 원소도 집어넣을 수 있는 자료구조.
	// key, value 형태로 집어넣을 필요도 없고, 넣으면 자동으로 정렬됨
	multiset<int> s;

	s.insert(12);
	s.insert(10);
	s.insert(2);
	s.insert(10);
	s.insert(90);
	s.insert(85);
	s.insert(45);

	cout << "Multiset elements after sort\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	cout << "\n";

	auto it1 = s.find(10);
	auto it2 = s.find(90);

	// elements from 10 to elements before 90
	// erased
	s.erase(it1, it2);

	cout << "Multiset Elements after erase:\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << ' ';
	s.erase(s.begin());
	cout << "\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << ' ';
}

void MakeSet() {
	// 중복되는 요소는 없고 오로지 유니크한 값만 저장해버리는 자료구조
	set<pair<string, int>> _set;

	_set.insert({ "test", 1 });
	_set.insert({ "test", 1 });
	_set.insert({ "test", 1 });
	_set.insert({ "test", 1 });

	cout << _set.size() << "\n";
}

void MakeMap() {
	int v[10];
	unordered_map<string, int> umap;
	
	// 이렇게 넣기도 가능
	umap.insert({ "test1", 1 });

	// 이렇게 넣을수도 있음
	umap.emplace("test5", 5);

	// 또한 이렇게 변경도 가능, 추가할 수도 있음. 아래를 권장
	umap["test1"] = 4;

	for (auto element : umap) {
		cout << element.first << " :: " << element.second << '\n';
	}

	// map의 find 메소드는 찾지 못하면 end() 이터레이터를 반환
	auto search = umap.find("test1");
	if (search != umap.end()) {
		cout << "found :" << search->first << " " << (*search).second << '\n';
	}
	else {
		cout << "not found.." << '\n';
	}

	// 이런 식으로 바로 int형을 증가시킬 수 있음
	umap["test1"]++;
	cout << umap["test1"] << '\n';

	cout << umap.size() << '\n';
	umap.erase("test1");
	cout << umap.size() << '\n';
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

