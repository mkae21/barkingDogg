#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//�� ��Ʈ�� 6,9�� ���� ���ڷ� ���
	int input;
	cin >> input;

	int numbers[10] = {};

	while (input > 0) { //������ �ϳ��� �˻�
		if (input % 10 == 6 || input % 10 == 9)
			numbers[6]++;
		else
			numbers[input % 10]++;

		input /= 10;
	}

	
	if (numbers[6] % 2 == 1) {
		++numbers[6] /= 2;
	}
	else
		numbers[6] /= 2;

	cout << *max_element(numbers, numbers + 10);
	
}