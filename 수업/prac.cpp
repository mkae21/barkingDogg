#include <bits/stdc++.h>

using namespace std;


void moveLeft(deque<int>& dq,int left,int& total)
{
    while(left--)
    {
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
        total++;
    }

    dq.pop_front();
    // cout << "MoveLeft 함: " <<total << '\n';
}

void moveRight(deque<int>& dq,int right ,int& total)
{
    while(right--)
    {
        int tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);
        total++;
    }

    dq.pop_front();
    // cout << "MoveRight 함:" <<total << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;

    int n,m;
    int total = 0;

    cin >> n >> m;


    for(int i = 1 ; i <= n ; i++)
        dq.push_back(i);

    //target의 index를 찾아서 
    //compare the index of from begin with from end
    
    while(m--)
    {

        int target;
        cin >> target;

        // for(auto& c : dq)
        //     cout << c << " ";

        //index
        int left = 0;
        int right = 0;
        
        while(target != dq[left])
        {
            left++;
        }

        //실제 index보다 한번 더 옮겨야함, 그래야 front에 제대로 target 위치함
        right = dq.size() - left;

        // cout << "Left: " << left << " Right: " << right;
        // cout <<'\n';

        if(left < right)
            moveLeft(dq,left,total);
        else
            moveRight(dq,right,total);

    }

    cout << total;

    return 0;
}