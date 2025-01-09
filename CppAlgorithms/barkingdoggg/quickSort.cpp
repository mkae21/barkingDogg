//퀵 정렬 : 분할 정복 알고리즘, 배열의 알고리즘을 반복적으로 분할, O(N+logN)
#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {
	int pl = start;
	int pr = end;

	int key = arr[(pl + pr) / 2]; // 중앙 값

	while (pl <= pr) {

		while (arr[pl] < key) // 키 값보다 작을 때 통과
			pl++;

		while (arr[pr] > key) // 키 값보다 클때 통과 
			pr--;
	
		if (pl <= pr) { // 값 교환
			swap(arr[pl], arr[pr]);

			//교환 이후 다음 걸로 넘어가야함
			pl++;
			pr--;
		}

	}

	
}

//3 7 8 1 5 9 6 10 2 4를 정렬
// pivot에 위치에 따라 성능이 많이 변경된다.
int main() {

	vector<int> arr = { 3, 7, 8, 1, 5, 9, 6, 10 , 2 , 4 };

	int n = arr.size();
	
	cout << "정렬 전: ";

	for (int i : arr)
		cout << i << " ";


	cout << "정렬 후: ";

	for (int i : arr)
		cout << i << " ";


	return 0;
}