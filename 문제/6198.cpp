#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long total = 0;
    long long h;

    stack<int> s;

    while(n--){
        cin >> h;

        while(!s.empty() && s.top() <= h)
            s.pop();
            
        total += s.size();
        s.push(h);
    }

    cout << total;

    return 0;
}