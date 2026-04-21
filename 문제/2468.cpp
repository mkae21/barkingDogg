#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
int maxLevel = 0;

int map[105][105];
int temp[105][105];
vector<int> res;

//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        {
            cin >> map[i][j];

            if(maxLevel < map[i][j]) //최대 값 갱신
                maxLevel = map[i][j];
        }

    queue<pair<int,int>> q;

    //비가 오지 않는 경우도 존재
    for(int waterLv = 0 ; waterLv <= maxLevel ; waterLv++)
    {
        //반복을 위한 배열 복사
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                temp[i][j] = map[i][j];

                if(temp[i][j] <= waterLv) //침수 시키기
                    temp[i][j] = -1; 
            }
        }

        int cnt = 0;

        //전 범위 bfs
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                //침수당하지 않은 곳, 방문하지 않은 곳
                if(temp[i][j] != -1 && temp[i][j] != 200)
                {
                    //시작점
                    q.push({i,j});
                    temp[i][j] = 200; //200을 방문처리로 지정
                    cnt++;

                    while(!q.empty())
                    {
                        pair<int,int> cur = q.front();
                        q.pop();

                        for(int dir = 0 ; dir < 4 ; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                                continue;

                            //이미 방문한 곳, 이미 침수가 된 곳
                            if(temp[nx][ny] == 200 || temp[nx][ny] == -1)
                                continue;
                            
                            q.push({nx,ny});
                            temp[nx][ny] = -1; //방문 처리
                        }
                    }

                }
            }
        }


        res.push_back(cnt);
    }

    cout << *max_element(res.begin(),res.end());
    return 0;
}
