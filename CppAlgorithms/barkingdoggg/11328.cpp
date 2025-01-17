#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //case numbers

	cin >> N;
	

	while (N--) {
		int a[26] = {}; //�� ������ ���� ���� �迭

		string s1, s2;
		cin >> s1, s2;

		for (auto c : s1) //���� ���� ��ŭ ++
			a[c - 'a']++;
		for (auto c : s2)//¦���� ���� ��ŭ --
			a[c - 'a']--;

		bool isPossible = true;

		for (int i : a) {
			if (i != 0) // ���� ���ڰ� ������ false
				isPossible = false;
		}

		if (isPossible)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}

	return 0;
}