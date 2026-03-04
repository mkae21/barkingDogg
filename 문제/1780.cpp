#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int cnt[3]; // -1,0,1 순 저장


//범위 check
bool check(int x, int y, int n){
    for(int i = x ; i < x + n ; i++ ){
        for(int j = y; j < y + n ; j++){
            if(paper[x][y] != paper[i][j])
                return false;
        }
    }

    return true;
}

//범위 검사 후, 전부 일치하지 않으면 9 등분
void func(int x, int y, int n){ 
    //일치할 경우
    if(check(x,y,n)){
        cnt[paper[x][y] + 1] += 1;
        return;
    }

    //9등분 몫
    n = n/3;

    for(int i = 0; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++){
            func(x + n*i, y + n*j, n);
        }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    //paper 초기화
    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < n ;j++)
            cin >> paper[i][j];

    func(0,0,n);

    for(auto c: cnt)
        cout << c << '\n';

    return 0;
}