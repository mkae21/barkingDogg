#include <iostream>
#include <climits>
#include <queue>

using namespace std;
int k;
int x,y;
int board[205][205];
int dp[205][205][35]; //i,j 좌표까지 가는데 hx 사용,

struct State{
    int x;
    int y;
    int k;
};

//8~11이 상하좌우
int hx[8] = {-1,-2,-1,-2,1,2,1,2};
int hy[8] = {-2,-1,2,1,-2,-1,2,1};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> y >> x;

    for(int i = 0 ; i < x; i++)
        for(int j = 0 ; j < y ; j++)
            cin >> board[i][j];

    //dp 값 초기화
    for(int i = 0 ; i < x ; i++)
        for(int j = 0 ; j < y ; j++)
            for(int k = 0 ; k < 35 ; k++)
                dp[i][j][k] = INT_MAX;

    //초기화
    queue<State> q;
    State start = {0,0,0};
    int idx;
    q.push(start);
    dp[0][0][0] = 0;

    while(!q.empty())
    {
        State cur = q.front();
        q.pop();

        //
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            //범위 검사
            if(nx < 0 || ny < 0 || nx >= x || ny >= y)
                continue;
            
            //이전에 방문했을 때 보다 값이 클 때, 장애물이 존재할 때
            if(dp[nx][ny][cur.k] <= dp[cur.x][cur.y][cur.k] + 1|| board[nx][ny] == 1)
                continue;
            
            dp[nx][ny][cur.k] = dp[cur.x][cur.y][cur.k] + 1;
            q.push({nx,ny,cur.k});
        }

        if(cur.k < k) //말 범위 한번 실행
        {
            for(int i = 0 ; i < 8 ; i++)
            {
                int nx = cur.x + hx[i];
                int ny = cur.y + hy[i];

                //범위 검사
                if(nx < 0 || ny < 0 || nx >= x || ny >= y)
                    continue;
                
                //이전에 방문했을 때 보다 값이 클 때, 장애물이 존재할 때
                //이때, 현재보다 k + 1인 상태와 비교해야한다.
                if(dp[nx][ny][cur.k + 1] <= dp[cur.x][cur.y][cur.k] + 1|| board[nx][ny] == 1)
                    continue;
                
                dp[nx][ny][cur.k + 1] = dp[cur.x][cur.y][cur.k] + 1;
                q.push({nx,ny,cur.k + 1});
            }
        }


    }
             

    int minValue = dp[x-1][y-1][0];
    bool isFailed = true;

    for(int i = 0 ; i <= k ; i++)
    {
        //하나라도 INT_MAX가 아니라면
        if(dp[x-1][y-1][i] != INT_MAX)
            isFailed = false;
    }

    if(isFailed)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0 ; i <= k ; i++)
    {
        minValue = min(dp[x-1][y-1][i],minValue);
    }
    cout << minValue;

}