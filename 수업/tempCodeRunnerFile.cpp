#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    //stack 초기화
    for(int i = 0; i < n ; i++)
    {
        int num;
        cin >> num;

        s.push(num);
    }

    //init
    arr[n--] = -1;

    int max = s.top();
    int prev = s.top();
    int idx = s.size();

    s.pop();

    
    while(!s.empty())
    {

        if(s.top() < prev)
        {
            arr[n--] = prev;
            prev = s.top();
        }
        else// prev 보다 크거나 같을 때
        {
            if(s.top() >= max)
            {
                arr[n--] = -1;
                prev = s.top();
                max = s.top();
            }
            else
            {
                arr[n--] = max;
                prev = s.top();
            }
        }

        s.pop();
    }

    for(int i = 1 ; i <= idx ; i++)
        cout << arr[i] << " ";

    return 0;
}