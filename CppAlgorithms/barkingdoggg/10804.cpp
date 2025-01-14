#include <bits/stdc++.h>

using namespace std;

void swapValue(int* arr, int start, int end) {
	int i = start - 1;
	int j = end - 1;
	int temp;

	while (i <= j) { //같을 때는 가능
		temp = arr[i];
		arr[i++] = arr[j];
		arr[j--] = temp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int start, end;
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	for (int i = 0; i < 10; i++) {
		cin >> start >> end;
		swapValue(arr, start, end);
	}

	for (int num : arr) { // arr의 크기를 알아서 사용 가능.
		cout << num << " ";
	}

}