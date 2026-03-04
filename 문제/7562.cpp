#include <bits/stdc++.h>
//제한 시간 1초 : 100000000번
using namespace std;

int chessboard[301][301];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test_case,size;
    int cur_x,cur_y,target_x,target_y;

    cin >> test_case;

    //test case 만큼
    while(test_case--){

        cin >> size >> cur_x >> cur_y >> target_x >> target_y;

        //미방분 -1
        for(int i = 0 ; i < 301 ; i++)
            fill(chessboard[i],chessboard[i]+ 301,-1);

        queue<pair<int,int>> q;
        q.push({cur_x,cur_y});
        chessboard[cur_x][cur_y] = 0; // 시작점 방문 처리

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            
            // cout << "x: " << cur.first << " y: " << cur.second << '\n';
            //조건 확인
            if(cur.first == target_x && cur.second == target_y){
                cout << chessboard[cur.first][cur.second] << '\n';
                break;
            }
            

            for(int i = 0 ; i < 4 ; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || nx >= size || ny < 0 || ny >= size)
                    continue;
                
                if(chessboard[nx][ny] >= 0) //방문한곳 가지 않기
                    continue;
                
                // cout << "\n넣기전: " << cur.first << " " << cur.second << '\n';

                //조건 확인
                chessboard[nx][ny] = chessboard[cur.first][cur.second] + 1;
                q.push({nx,ny});
            }

        }
    }
}