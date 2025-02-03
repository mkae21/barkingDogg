#include <bits/stdc++.h>

using namespace std;

//시간 제한: 1.5초 N: 500,000

int dis[100000001]; // 높이 배열

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s; // 입력 저장
    stack<int> ans; //정답 저장
    queue<int> temp; //임시 저장
    
    int n,input;
    int idx = 0;
    cin >> n;

    while(n--){ //초기화
        cin >> input;
        dis[input] = idx++;
        s.push(input);
    }




    return 0;
}