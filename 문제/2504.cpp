#include <bits/stdc++.h>

using namespace std;

unsigned long long ans = 0;

//입력이 ) -> 바로 직전이  ( 일 때 2, 다음 거 검사?

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len;
    
    stack<char> s;
    string str;
    cin >> str;
    len = str.length();

    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if(str[i] == ')')
        {
            if(s.empty())
            {
                cout << 0;
                return 0;
            }

            if(str[i-1] == '(' && (str[i+1]))
            {
                s.pop();
            }
        }
        else   // str[i] == ']'
        {
            
        }
    }

    return 0;
}