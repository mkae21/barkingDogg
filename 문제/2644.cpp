#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[105];
bool visited[105];
bool isFinished = false;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int peopleCnt;
    int tar1,tar2;
    int relation;

    cin >> peopleCnt >> tar1 >> tar2 >> relation;

    //양방향 그래프로 해야지 문제 해결에 쉬울 것 같다.
    for(int i = 1 ; i <= relation ; i++)
    {
        int s,e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    //순회
    //현재 노드, 촌수
    queue<pair<int,int>> q;
    q.push({tar1,1});
    visited[tar1] = true;
    
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        int curNode = cur.first;
        int curChon = cur.second;
        
        //해당 인접리스트의 크기 만큼
        for(auto e : graph[curNode])
        {
            //방문 여부
            if(visited[e] == true)
                continue;
            
            if(e == tar2) //얘를 꼭 해야하나?, 안하려면 따른 컨테이너 만들어서 사용할 것.
            {
                isFinished = true;
                break;
            }

            q.push({e,curChon + 1});
            visited[e] = true;
        }

        if(isFinished)
        {
            cout << curChon;
            return 0;
        }
    }

    cout << -1;

    return 0;
}