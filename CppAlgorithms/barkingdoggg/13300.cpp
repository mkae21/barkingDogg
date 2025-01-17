#include <bits/stdc++.h>

using namespace std;

int maleCnt[7];
int femaleCnt[7];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, S, Y;
	int roomCnt = 0;

	cin >> N >> K;
	
	//max N 1000, max K : 1000

	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		if (S)
			maleCnt[Y]++;
		else
			femaleCnt[Y]++;
	}

	//���� �� + ���� �� �� �ջ�

	for (int i = 1; i < 7; i++) {
		
		if (maleCnt[i] == 0) // �ο��� ���� ��
			continue;

		int portion = maleCnt[i] / K;
		int res = maleCnt[i] % K;

		if (res) { // �� �� �� �߰�
			roomCnt += ++portion;
		}
		else
			roomCnt += portion;
	}


	for (int i = 1; i < 7; i++) {

		if (femaleCnt[i] == 0) // �ο��� ���� ��
			continue;

		int portion = femaleCnt[i] / K;
		int res = femaleCnt[i] % K;

		if (res) { // �� �� �� �߰�
			roomCnt += ++portion;
		}
		else
			roomCnt += portion;
	}

	cout << roomCnt;

	return 0;
}