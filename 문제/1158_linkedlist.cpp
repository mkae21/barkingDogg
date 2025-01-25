#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    int cnt = 1;
    // vector<int> answer;
    
    list<int> circular;

    cin >> n >> k;
    
    for(int i = 1 ; i <= n ; i++){
        circular.push_back(i);
    }

    auto it = circular.begin();

    cout << '<';
    int temp = 1;
    while(circular.size() > 1){

        // cout << "반복 수: " << temp++ << '\n';
        // cout << "현재 cnt: " << cnt << '\n';
        // cout << "현재 it: " << *it << '\n';
        // cout << '\n';
        if(cnt == k){ //삭제후 다음 위치 반환
            cout << *it <<", ";
            it = circular.erase(it);//여기서 이미 이동
            cnt = 1;

        }else{
            ++it;
            ++cnt;
        }

        if(it == circular.end())
            it = circular.begin();
    }
    
    cout << circular.front();
    cout << '>';

    return 0;
}