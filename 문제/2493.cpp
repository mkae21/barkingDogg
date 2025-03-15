#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> tower;
    tower.push({100000001,0});
    
    int n; 

    cin >> n; // 횟수


    for(int i = 1 ; i <= n ; i++){
        int height;
        cin >> height;

        while(tower.top().first <= height)
            tower.pop();

        cout << tower.top().second << " ";
        
        tower.push({height,i});
    }

    return 0;
}

//stack에는 항상 입력받는 타워의 도착 타워가 top에 있어야 한다..