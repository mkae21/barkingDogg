#include <bits/stdc++.h>

using namespace std;

string str;

long long ans = 0; //몇개가 나올지 모르니까 일단 제일 크게

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack <char> s;

    cin >> str;
    int len = str.length();

    for(int i = 0; i < len ; i++)
    {
        // '(' 입력 받을 때
        if(str[i] == '(')
            s.push(str[i]);
        else // ) 입력
        {
            if(str[i-1] == '(')//레이저 일 때
            {
                s.pop();
                ans += s.size(); //s는 ( 만 존재
            }
            else //막대 끝났을 때
            {
                s.pop();
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}