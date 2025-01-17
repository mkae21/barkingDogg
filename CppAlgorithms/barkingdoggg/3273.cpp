#include <bits/stdc++.h>

using namespace std;

int numbers[2000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	int cnt = 0;

	vector<int> arr;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cin >> x;

	for (int i = 0; i < n; i++) {
		int val = x - arr[i];

		if (numbers[val] && val > 0)
			cnt++;
		numbers[arr[i]]++;
	}

	cout << cnt;
}