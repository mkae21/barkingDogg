#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <int> v1(3, 5); //사이즈 3,5로 초가화 (5,5,5)
	cout << v1.size() << '\n'; // 3
	v1.push_back(7); // (5,5,5,7)

	vector<int> v2(2); //(0,0)
	v2.insert(v2.begin() + 1, 3); //(0,3,0)

	vector<int> v3 = { 1,2,3,4 };
	v3.erase(v3.begin() + 2); //{1,2,4}

	vector<int> v4;
	v4 = v3; // {1,2,4}, 이때 깊은 복사로 수행됨.
	cout << v4[0] << v4[1] << v4[2] << '\n'; //124
	v4.pop_back();
	v4.clear();


	for (int& e : v1)
		cout << e << ' ';

	return 0;
}