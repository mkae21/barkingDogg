#include <bits/stdc++.h>
using namespace std;

int n,s,cnt;
int arr[25];

void func(int curIdx, int total)
{
    if(curIdx >= n)
    {
        if(total == s)
            cnt++;
        return;
    }    
    //더하지 않았을 경우
    func(curIdx + 1 , total);

    //더했을 경우
    func(curIdx + 1 , total + arr[curIdx]);
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i =0 ; i< n ; i++)
        cin >> arr[i];

    func(0,0);
    cnt -= 1; // 공집합 제외
    cout << cnt ;
    return 0;
}