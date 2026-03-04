#include <bits/stdc++.h>
using namespace std;

int paper[130][130];
int cnt[2];//0,1 -> 흰색, 파란색

bool check(int x, int y, int n){
    for(int i = x ; i < x + n ; i++){
        for(int j = y ; j < y + n ; j++){
            if(paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

void func(int x,int y, int n){

    if(check(x,y,n)){//동일한 숫자
        cnt[paper[x][y]] += 1; //값에 맞는 cnt 올리기
        return;//base condition
    }

    n = n/2; // 4 등분

    for(int i = 0 ; i < 2; i++)
        for(int j = 0 ; j < 2 ; j++)
            func(x + n*i, y + n*j , n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    //초기화
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> paper[i][j];
        }
    }

    func(0,0,n);

    for(auto& c : cnt)
        cout << c << '\n';

    return 0;
}