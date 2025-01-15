#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;	
	cin >> s;

	for (char c = 'a'; c <= 'z'; c++) {
		int cnt = 0;
		for (auto e : s) {
			if (c == e)
				cnt++;
		}
		cout << cnt << ' ';
	}

	return 0;
}