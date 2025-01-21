#include <bits/stdc++.h>

using namespace std;

int numbers[11];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;

    cin >> a >> b >> c;
    
    string total = to_string(a*b*c); // to_string 문법 알아야 쓰지..

    for(char c: total)
        numbers[c - '0']++; //아스키 코드 계산
    
    for(auto c: numbers)
        cout<< c << "\n";
    
    return 0;
}