#include <bits/stdc++.h>
using namespace std;

//6 - start - end : 나머지 한 장대의 좌표

void func(int start,int end, int n){
    
    if(n == 1){
        cout << start << " " << end <<'\n';
        return;
    }


    //n-1개 start -> 나머지 한 장대
    func(start,6-start-end,n-1);
    //n 번째 start -> end
    cout << start << " " << end <<'\n';
    //n-1개 나머지 장대 -> end
    func(6-start-end,end,n-1);
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    func(1,3,n);

    return 0;
}