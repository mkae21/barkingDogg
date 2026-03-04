#include <bits/stdc++.h>
using namespace std;

int n,m; //입력 값
int arr[10]; // 배열
bool isused[10]; // 사용 여부 배열 (1부터 사용중)


//현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수이다.
void func(int k){
    if(k == m){ //m개까지 모두 택했을 때
        for(int i = 0 ; i < m ; i++)
            cout << arr[i] << ' ';
        cout << '\n';₩
        return;
    }

    for(int i = 1 ; i <= n ; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);//해당 과정이 모두 끝나면 현재 사용하는 것을 초기화
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0); 

}