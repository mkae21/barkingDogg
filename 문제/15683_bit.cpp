#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int cctvCnt = 0;
int room1[10][10]; //원본
int room2[10][10]; //수행용
vector<pair<int,int>> cctvs;

int minValue = 1e6;

//북서남동
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

//dir 방향으로 계속 체크
void check(int x, int y, int dir)
{
    dir %= 4;

    while(1)
    {
        //한 방향으로만 전진하게된다.
        x += dx[dir];
        y += dy[dir];

        //범위 검사
        if(x < 0 || y < 0 || x >= n || y >= m)
            break;

        if(room2[x][y] != 0)
        {
            if(room2[x][y] == 6) //6 만나면 끝
                break;

            continue; //cctv는 건너 뛰기, 이미 본 곳은 건너 뛰기
        }

        room2[x][y] = -1; //봤으면 표시 남기기

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> room1[i][j];
            if(room1[i][j] != 0 && room1[i][j] != 6)
            {
                cctvCnt++;
                cctvs.push_back({i,j});
            }
        }
    }

    //cctv cnt만큼의 4진수 조합 수
    //ex) 4개 -> 0 ~ 4^n - 1까지
    for(int tmp = 0 ; tmp < (1 << 2 * cctvCnt) ; tmp++)
    {
        //검사용 복사
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                room2[i][j] = room1[i][j];
            }
        }

        int numo = tmp;

        //cctv 갯수만큼 -> 각 자리수의 방향 추출하는 과정
        for(int i = 0 ; i < cctvCnt ; i++)
        {
            //4진수 화
            int dir = numo % 4;
            numo /= 4; //다음 자리

            int x = cctvs[i].first;
            int y = cctvs[i].second;

            if(room2[x][y] == 1) //한 방향으로
            {
                check(x,y,dir);
            }
            else if(room2[x][y] == 2)
            {
                check(x,y,dir);
                check(x,y,dir + 2);
            }
            else if(room2[x][y] == 3)
            {
                check(x,y,dir);
                check(x,y,dir + 3);
            }
            else if(room2[x][y] == 4)
            {
                check(x,y,dir);
                check(x,y,dir + 1);
                check(x,y,dir + 2);
            }
            else // 5일 경우
            {
                check(x,y,dir);
                check(x,y,dir + 1);
                check(x,y,dir + 2);
                check(x,y,dir + 3);
            }


        }

        int darkArea = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(room2[i][j] == 0)
                    darkArea++;
            }
        }

        minValue = min(minValue, darkArea);
    }

    cout << minValue;

    return 0;
}