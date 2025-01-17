#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //case numbers

	cin >> N;
	

	while (N--) {
		int a[26] = {}; //각 문자의 개수 저장 배열

		string s1, s2;
		cin >> s1, s2;

		for (auto c : s1) //문자 갯수 만큼 ++
			a[c - 'a']++;
		for (auto c : s2)//짝지은 문자 만큼 --
			a[c - 'a']--;

		bool isPossible = true;

		for (int i : a) {
			if (i != 0) // 남는 숫자가 있으면 false
				isPossible = false;
		}

		if (isPossible)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}

	return 0;
}