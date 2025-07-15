#include <bits/stdc++.h>

using namespace std;

int paper[500][500];
int visited[500][500];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    int max_tile_paint = 0;
    int paint_cnt = 0;
    int cur_tile_cnt;

    queue<pair<int,int>> q;

    cin >> n >> m;

    //paper 초기화
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int input;
            cin >> input;
            paper[i][j] = input;
        }
    }

    //paper count
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(visited[i][j] || !paper[i][j])
                continue;
            
            q.push({i,j});
            visited[i][j] = 1;

            //그림 갯수
            paint_cnt++;

            //현재 paint tile cnt, 시작 tile도 포함해야함
            cur_tile_cnt = 1;

            while(!q.empty())
            {   
                pair<int,int> cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4 ; dir++)
                {  
                    int next_x = cur.first + dx[dir];
                    int next_y = cur.second + dy[dir];

                    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                        continue;
                    
                    if(visited[next_x][next_y] || !paper[next_x][next_y])
                        continue;
                    
                    cur_tile_cnt++;
                    visited[next_x][next_y] = 1;
                    q.push({next_x,next_y});
                }

            }
            max_tile_paint = max(cur_tile_cnt,max_tile_paint);
        }
    }

    cout << paint_cnt << '\n' << max_tile_paint;

    return 0;
}