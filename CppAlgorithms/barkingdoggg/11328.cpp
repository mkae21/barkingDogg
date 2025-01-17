#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //case numbers

	cin >> N;

	for (int i = 0; i < N; i++) {
		int store[1000] = {};
		string left;
		string right;

		cin >> left >> right;

		if (left.size() != right.size()) { //길이 비교
			cout << "Impossible" << "\n";
			continue;
		}

		for (int k = 0; k < left.size(); k++) { //알파벳 유무 저장
			store[left[k] - 'a']++;
			//cout << "left index: " << left[k] - 'a' << '\n';
		}

		for (int j = 0; j < right.size(); j++) {
			//cout << "right index: " << right[j] - 'a' << '\n';
			
			if (store[right[j] - 'a'] == 0) {
				cout << "Impossible" << "\n";
				break;
			}
			else {
				store[right[j] - 'a']--;
			}

			if(j == right.size() - 1)
				cout << "Possible" << '\n';
		}


	}

	return 0;
}