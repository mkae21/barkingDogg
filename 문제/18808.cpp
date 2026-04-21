#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int n,m,k;
int r,c;

int paper[42][42];
int sticker[12][12];

void rotate()
{
    int temp[12][12]; //원본을 유지시키기 위해

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            temp[i][j] = sticker[i][j];
        }
    }

    //90도 돌리면 r,c 변경된다.
    for(int i = 0 ; i < c ; i++)
    {
        for(int j = 0 ; j < r ; j++)
        {
            sticker[i][j] = temp[r-1-j][i]; 
        }
    }

    swap(r,c);
}

bool check(int x, int y) //해당 좌표에서
{
    //paper 남은 자리 순환하면서 붙일 공간이 있는지 확인
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            //이미 스티커가 붙어있을 때
            if(paper[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;

    //가능하면 붙이기
    for(int i = 0 ; i < r; i++)
        for(int j = 0 ; j < c ; j++)
        {
            if(sticker[i][j] == 1)
                paper[x+i][y+j] = 1;
        }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    //스티커 갯수 만큼 반복
    while(k--)
    {
        cin >> r >> c;

        //스티커 입력
        for(int i = 0 ; i < r ; i++)
            for(int j = 0; j < c ; j++)
                cin >> sticker[i][j];

        //붙일수 있는지 확인
        for(int rot = 0 ; rot < 4 ; rot++) //각 스트커 90도 4번씩 돌려야함
        {
            bool isPossible = false;
            
            //범위를 제대로 지정해줘야 검사를 할 수 있다.
            for(int i = 0 ; i <= n - r ; i++)
            {
                if(isPossible)
                    break;

                for(int j = 0 ; j <= m - c ;j++)
                {
                    if(check(i,j)) //붙일 수 있다 -> 다음 스티커로 넘어가야 함
                    {
                        isPossible = true;
                        break;
                    }
                }
            }

            if(isPossible)
                break;

            rotate();//돌리기
        }
        
    }

    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(paper[i][j] == 1)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}