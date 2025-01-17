#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string one, two;
	
	int stored[2][26] = {};
	int delChar = 0;

	cin >> one >> two;

	for (int i = 0; i < one.size(); i++)
		stored[0][one[i] - 'a']++;

	for (int i = 0; i < two.size(); i++)
		stored[1][two[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		delChar += abs(stored[0][i] - stored[1][i]);

	

	//for (int c : stored)
	//	cout << c << " ";

	cout << delChar;


}