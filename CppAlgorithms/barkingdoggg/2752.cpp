#include <bits/stdc++.h>

using namespace std;


int main() {

	ios::sync_with_stdio(0); // 시간 초과 방지
	cin.tie(0);


	vector<int> arr(3); // 벡터
	
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}