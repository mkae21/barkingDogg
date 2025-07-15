#include <bits/stdc++.h>

//1억번 연산 제한.
using namespace std;

//상,하,좌,우
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int box[1002][1002];
int dist[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n;
    cin >> m >> n;

    queue<pair<int,int>> q;

    //box 초기화
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> box[i][j];

            if(box[i][j] == 1) //0 이 아닌 모든 수가 참이 된다.
                q.push({i,j});

            if(box[i][j] == 0)
                dist[i][j] = -1;
        }
    }


    //bfs
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        for(int dir = 0 ; dir < 4 ; dir++)
        {
            
            int new_x = cur.first + dx[dir];
            int new_y = cur.second + dy[dir];
            
            //범위 검사
            if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
                continue;

            //방문 검사 및 유효 타일 검사
            if(dist[new_x][new_y] >= 0)
                continue;

            dist[new_x][new_y] = dist[cur.first][cur.second] + 1;
            q.push({new_x,new_y});
        }
    }

    int cnt = 0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            cnt = max(cnt,dist[i][j]);
        }
    }
    cout << cnt;
    return 0;
}