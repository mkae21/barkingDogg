#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
string map[27];
bool isVisited[27][27];

std::vector<int> res;

//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    //map 입력받기
    for(int i = 0 ; i < n ; i++)
        cin >> map[i];

    queue<pair<int,int>> q;

    //map 순회
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            //모든 좌표 순회하면서 bfs 돌리기
            if(map[i][j] == '1' && isVisited[i][j] == 0)
            {
                q.push({i,j}); //시작점 넣기
                isVisited[i][j] = 1; 
                int cnt = 1; //타일 계산 용

                while(!q.empty())
                {
                    pair<int,int> cur = q.front();
                    q.pop();

                    for(int dir = 0 ; dir < 4 ; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        //범위 검사
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        
                        if(isVisited[nx][ny] == 1 || map[nx][ny] == '0') //방문했거나, 끊겨있다면
                            continue;

                        isVisited[nx][ny] = 1; //방문처리하고 
                        q.push({nx,ny}); //큐에 넣기
                        cnt++;

                    }
                }
                //bfs 끝나면 res에 넣기
                res.push_back(cnt);
            }
        }
    }

    std::sort(res.begin(),res.end());
    
    cout << res.size() << '\n';

    for(auto& c : res)
        cout << c << '\n';

    return 0;
}