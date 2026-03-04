#include <bits/stdc++.h>
using namespace std;

int office[10][10];
bool isUsed[10];
int cctvCnt;
int n,m;
int changedCnt;
int minCnt = 2100000000;

std::vector<pair<int,int>> cctvIdx;
std::vector<pair<int,int>> changed;

void up(int x, int y){
    for(int i = x ; i >= 0 ; i--){
        if(office[i][y] == 0){
            changed.push_back({i,y});
            office[i][y] = '#';
            changedCnt++;
        }

        //벽 뒤로는 갈 수 없다.
        if(office[i][y] == 6)
            break;
    }
}

void down(int x, int y){
    for(int i = x ; i < n ; i++){
        if(office[i][y] == 0){
            changed.push_back({i,y});
            office[i][y] = '#';
            changedCnt++;
        }
        if(office[i][y] == 6)
            break;
    }
}


void right(int x, int y){
    for(int j = y ; j < m ; j++){
        if(office[x][j] == 0){
            changed.push_back({x,j});
            office[x][j] = '#';
            changedCnt++;
        }

        if(office[x][j] == 6)
            break;
    }
}


void left(int x, int y){
    for(int j = y ; j >= 0 ; j--){
        if(office[x][j] == 0){
            changed.push_back({x,j});
            office[x][j] = '#';
            changedCnt++;
        }

        if(office[x][j] == 6)
            break;
    }
}

void revert(){

    //부모가 몇개 변경이 되었는지 확인
    int parentsChangedCnt = changed.size() - changedCnt;

    for(int i = 0 ; i < changedCnt - parentsChangedCnt ; i++){
        
        //초기화 처리한 것은 다시 되돌려야함
        pair<int,int> cur = changed.back();
        changed.pop_back();

        office[cur.first][cur.second] = 0; //복구
    }

    //초기화
    changedCnt = parentsChangedCnt;
}


void countZero(){
    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(office[i][j] == 0)
                cnt++;
        }
    }

    minCnt = min(cnt,minCnt);
}

void func(int cnt){
    if(cnt > cctvCnt){
        //0 갯수 카운팅
        countZero();
        return;
    }


    for(int i = 0 ; i < cctvCnt ; i++){
        if(!isUsed[i]){
            int y = cctvIdx[i].second;
            int x = cctvIdx[i].first;
            
            int cctvNum = office[x][y];
            
            isUsed[i] = true;
            
            if(cctvNum == 1){
                up(x,y);
                func(cnt + 1);
                revert();
                
                down(x,y);
                func(cnt + 1);
                revert();

                left(x,y);
                func(cnt + 1);
                revert();

                right(x,y);
                func(cnt + 1);
                revert();

            }
            else if(cctvNum == 2){
                right(x,y);
                left(x,y);
                func(cnt+1);
                revert();

                up(x,y);
                down(x,y);
                func(cnt + 1);
                revert();
            }
            else if(cctvNum == 3){
                up(x,y);
                right(x,y);
                func(cnt+1);
                revert();

                right(x,y);
                down(x,y);
                func(cnt + 1);
                revert();

                down(x,y);
                left(x,y);
                func(cnt + 1);
                revert();

                left(x,y);
                up(x,y);
                func(cnt + 1);
                revert();
            }
            else if(cctvNum == 4){
                up(x,y);
                left(x,y);
                right(x,y);
                func(cnt + 1);
                revert();

                up(x,y);
                right(x,y);
                down(x,y);
                func(cnt + 1);
                revert();

                right(x,y);
                down(x,y);
                left(x,y);
                func(cnt + 1);
                revert();

                down(x,y);
                left(x,y);
                up(x,y);
                func(cnt + 1);
                revert();
            }
            else{
                up(x,y);
                right(x,y);
                down(x,y);
                left(x,y);
                func(cnt + 1);
                revert();
            }
        }

        //각 cctv의 모든 과정이 끝나고나서 (모두 검사를 하고 나서 false 처리)
        isUsed[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    //방문 처리 초기화
    std::fill(isUsed,isUsed+10,0);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> office[i][j];

            //cctv 총 갯수
            if( 0 < office[i][j] && office[i][j] < 6){
                cctvCnt++;
                cctvIdx.push_back({i,j});
            }
        }
    }

    func(1);
    cout << minCnt << '\n';

    return 0;
}