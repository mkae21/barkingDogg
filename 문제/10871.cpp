//시간 제한 1초: 초당 1억번의 연산 가능
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> arr;
    int num,target;

    cin >> num >> target;

    for(int i = 0 ; i < num ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    for(int i = 0 ; i < num ; i++){
        if(arr[i] < target)
            cout << arr[i] << " ";
    }

    return 0;
}