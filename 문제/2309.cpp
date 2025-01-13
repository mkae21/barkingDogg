#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    int temp;

    for(int i = 0; i < 9 ; i++){ // 초기화
        cin >> temp;
        arr[i] = temp;
    }
    
    sort(arr,arr+9); // 오름차순 정렬 , 반복자에 대한 개념이 필요하다..

    int total = accumulate(arr,arr+9,0);


    for(int i = 0 ; i < 8 ; i++){ // n^3 이지만 최대 n이 9개라 괜찮음
        for(int j = i+1 ; j < 9 ; j++){
            
            temp = total;// 매 loop마다 다시 검사해야함
            
            if(temp - (arr[i] + arr[j]) == 100){ // 차가 100일 때
                for(int k = 0 ; k < 9 ; k++){
                    if(k == i || k == j)
                        continue;
                    cout << arr[k] << "\n";
                }
                return 0;
            }
        }
    }

}