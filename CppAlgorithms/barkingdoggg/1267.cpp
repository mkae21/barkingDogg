#include <bits/stdc++.h>

using namespace std;

int youngsik(int* arr, int size) {
	int total = 0;

	for (int i = 0; i < size; i++) {
		int portion = (arr[i] / 30) + 1; // 0초 통화도 10원이니까 
		
		total += (portion * 10);
	}

	return total;
}

int minsik(int* arr, int size) {
	int total = 0;

	for (int i = 0; i < size; i++) {
		int portion = (arr[i] / 60) + 1;

		total += (portion * 15);
	}

	return total;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int temp;

	cin >> N;
	
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	
	int Y = youngsik(arr, N);
	int M = minsik(arr, N);

	if (Y > M)
		cout << "M " << M;
	else if (Y < M)
		cout << "Y " << Y;
	else
		cout << "Y " << "M " << Y;


	delete []arr;
}