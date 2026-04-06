#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int operators[4];
int maxValue = -1000000001;
int minValue = 1000000001;

void func(int idx , int result)
{
    if(idx == n) //연산은 n - 1번 진행하기 때문에..
    {
        if(maxValue < result)
            maxValue = result;
        if(minValue > result)
            minValue = result;
        return;
    }

    for(int i = 0 ; i < 4 ; i++) //operator들 탐색
    {
        if(operators[i] > 0)
        {
            operators[i]--; //숫자 하나 줄이기
            
            if(i == 0) // +의 경우
                func(idx + 1, result + arr[idx]);
            else if(i == 1)
                func(idx + 1, result - arr[idx]);
            else if(i == 2)
                func(idx + 1 , result * arr[idx]);
            else
                func(idx + 1, result / arr[idx]);

            operators[i]++; //숫자 다시 복구
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    for(int i = 0 ; i < 4 ; i++)
        cin >> operators[i];
    
    func(1,arr[0]); //operand의 idx

    cout << maxValue << '\n' << minValue << '\n';
    
    return 0;
}