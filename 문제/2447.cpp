#include <bits/stdc++.h>
using namespace std;

char star[2200][2200];//이는 '\0'으로 초기화됨 -> 출력시 제대로된 결과가 나오지 않음.

void func(int x, int y, int n){
    if(n == 1){
        star[x][y] = '*';
        return;
    }

    int div = n/3;

    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3 ; j++){
            if(i == 1 && j == 1){ //가운데 부분은 뛰어넘어
                continue;
            }
            func(x + div*i, y + div*j, div);
        }
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
        fill(star[i], star[i]+n, ' ');

    func(0,0,n);


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;

}