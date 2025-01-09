//�� ���� : ���� ���� �˰���, �迭�� �˰����� �ݺ������� ����, O(N+logN)
#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {
	int pl = start;
	int pr = end;

	int key = arr[(pl + pr) / 2]; // �߾� ��

	while (pl <= pr) {

		while (arr[pl] < key) // Ű ������ ���� �� ���
			pl++;

		while (arr[pr] > key) // Ű ������ Ŭ�� ��� 
			pr--;
	
		if (pl <= pr) { // �� ��ȯ
			swap(arr[pl], arr[pr]);

			//��ȯ ���� ���� �ɷ� �Ѿ����
			pl++;
			pr--;
		}

	}

	
}

//3 7 8 1 5 9 6 10 2 4�� ����
// pivot�� ��ġ�� ���� ������ ���� ����ȴ�.
int main() {

	vector<int> arr = { 3, 7, 8, 1, 5, 9, 6, 10 , 2 , 4 };

	int n = arr.size();
	
	cout << "���� ��: ";

	for (int i : arr)
		cout << i << " ";


	cout << "���� ��: ";

	for (int i : arr)
		cout << i << " ";


	return 0;
}