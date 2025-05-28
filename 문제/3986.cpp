#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt = 0;
    cin >> n;


    while(n--)
    {
        stack<char> s;
        string input;
        cin >> input;
        
        for(int i = 0 ; i < input.size() ; i++)
        {
            if(s.empty() || s.top() != input[i])
                s.push(input[i]);
            else
                s.pop();
        }

        if(s.empty())
            cnt++;
    }

    cout << cnt;


    return 0;
}