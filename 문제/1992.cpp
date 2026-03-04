#include <bits/stdc++.h>
using namespace std;

string str[4100];

bool check(int x, int y, int n){
    for(int i = x ; i < x + n ; i++){
        for(int j = y ; j < y + n ; j++){
            if(str[x][y] != str[i][j])
                return false;
        }
    }

    return true;
}

void func(int x, int y, int n){
    if(check(x, y, n)){
        cout << str[x][y];
        return;
    }

    cout << '(';
    n = n/2;

    //x,y는 각각 starting point이다.
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            func(x + n*i , y + n*j, n);
        }
    }

    cout << ')';
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    //str 초기화
    for(int i = 0 ; i < n ; i++){
            cin >> str[i];
    }
    
    func(0,0,n);    

    return 0;
}