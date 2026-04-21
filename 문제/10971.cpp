#include <iostream>
#include <climits>
using namespace std;

int n;
int start;
int minValue = INT_MAX;
int cost[15][15];
bool visited[15]; //방문 여부

//lv는 방문한 노드 수
//lv를 이동 횟수로도 만들 수 있어.
void dfs(int cur , int dp, int lv)
{

    if(lv == n)
    {
        //길이 끊겨 있지 않아야 후보에 둔다.
        //분기가 끝나고 복귀했을 때, 값이 처음으로 돌아가 있어야함.
        if(cost[cur][start] != 0){
            minValue = min(minValue, dp + cost[cur][start]);
        }
        return;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        //비용이 0인 곳은 갈 수 없다.
        if(visited[i] == false && cost[cur][i] != 0)
        {
            visited[i] = true;
            dfs(i,dp + cost[cur][i],lv+1);
            visited[i] = false;
        }
    }

    }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    //비용 초기화
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> cost[i][j];

    for(int i = 1 ; i <= n ; i++)
    {
        start = i;
        visited[start] = true;
        dfs(i,0,1);
        visited[start] = false;
    }

    cout << minValue;
    return 0;
}