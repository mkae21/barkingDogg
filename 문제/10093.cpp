#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long start,end;

    cin >> start >> end;
    
    if(start == end) // 같을 때
        cout << 0;
    else if(start < end){ // end가 클 때
        cout << end - start - 1 << "\n";
        for(unsigned long long i = start + 1 ; i < end ; i++){
            cout << i << " ";
        }
    }
    else{ // start가 클 때
        cout << start - end - 1 << "\n";
        for(unsigned long long i = end + 1 ; i < start ; i++){
            cout << i << " ";
        }
    }

    return 0;
}