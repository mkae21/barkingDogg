#include <bits/stdc++.h>

using namespace std;

int result,input;

string res = "BCBAE"; //문자열을 만들어 두고

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int r = 0; r < 3 ; r++){
        result = 0;
        for(int c = 0 ; c < 4; c++){
            cin >> input;
            result += input;
        }

        cout << res[result] << "\n";
    }

    return 0;
}