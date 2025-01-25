#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;

    cin >> N >> K;
    
    queue<int> circular;
    int cnt = 1;

    for(int i = 1 ; i <= N ; i++) // 초기화
        circular.push(i);

    cout << '<';

    while(circular.size() > 1){
        int temp = circular.front();
        circular.pop();

        if(cnt % K == 0){
            cout << temp << ", "; // 얘는 문자열이니까..ㅠㅠ
        }else{ // K번째 아닐 때
            circular.push(temp);
        }
        cnt++;
    }

    cout << circular.back() << '>';
    

    return 0;
}