#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int office[10][10];
int row,col;

std::vector<pair<int,int>> cctvs{};

int minCnt = 1e9;

//우,상,좌,하
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void check(int x, int y, int dir)
{
    dir %= 4; // 굳이 필요한가?

    while(1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        x = nx;
        y = ny;

        //범위 검사
        if(nx < 0 || ny < 0 || nx >= row || ny >= col)
            return;

        //6일 경우 끝남
        if(office[nx][ny] == 6)
            return;
        
        //겹칠 가능성 있으니까,cctv 뚥기도 가능
        if(office[nx][ny] != 0)
            continue;


        office[nx][ny] = -1; //-1 집어넣기
    }
}


void func(int idx)
{
    //base condition
    if(idx == cctvs.size())
    {
        int cnt =  0;

        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++)
            {
                if(office[i][j] == 0) //사각 지대 세는 것
                    cnt++;
            }

        minCnt = min(cnt,minCnt);
        
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int temp[10][10]; //원상 복구 용


    //우,상,좌,하
    for(int dir = 0 ; dir < 4 ; dir++)
    {
        //각 단계별로 결과를 저장해야함.
        for(int i = 0; i < row ; i++)
            for(int j = 0 ; j < col ;j++)
                temp[i][j] = office[i][j];
        
        if(office[x][y] == 1)
        {
            check(x,y,dir);
        }
        else if(office[x][y] == 2)
        {
            check(x,y,dir);
            check(x,y,dir + 2);
        }
        else if(office[x][y] == 3)
        {
            check(x,y,dir);
            check(x,y,dir +1);
        }
        else if(office[x][y] == 4)
        {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        else if(office[x][y] == 5)
        {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }

        func(idx + 1);

        //초기화
        for(int i = 0; i < row ; i++)
            for(int j = 0 ; j < col ;j++)
                office[i][j] = temp[i][j];
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> row >> col;

    //초기화
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
        {
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6)
            {
                cctvs.push_back({i,j});
            }
        }

    func(0);
    cout << minCnt << '\n';
    return 0;
}