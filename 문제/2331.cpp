#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int a,p;
int check[240000]; //max 범위

void dfs(int n)
{
    if(check[n] == 2)
        return;

    check[n] += 1;

    int numo = n;
    int res = 0;
    
    while(numo != 0)
    {
        int val = numo % 10;
        numo /= 10;

        res += pow(val,p);
    }
    
    dfs(res);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> p;

    dfs(a);

    int cnt = 0;
    for(auto& c : check)
    {
        if(c == 1)
            cnt++;
    }

    cout << cnt << '\n';
    return 0;
}