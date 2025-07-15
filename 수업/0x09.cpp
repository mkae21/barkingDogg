#include <bits/stdc++.h>

using namespace std;

//BFS는 큐를 이용, DFS는 스택을 이용.
#define X first
#define Y second

int board[502][502];
int visited[502][502];

int n = 7,m = 10;

//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> q;
    visited[0][0];
    
    pair<int,int> start = {0,0};
    q.push(start);

    //큐가 빌 때까지
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //범위 지정
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            //방문 검사 및 블록 확인
            if(visited[nx][ny] || !board[nx][ny])
                continue;

            visited[nx][ny] = 1;
            q.push({nx,ny});
        }


    }

    return 0;
}