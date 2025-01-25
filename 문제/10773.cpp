#include <bits/stdc++.h>

using namespace std;

//1초라 O(N^2) 불 가능

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    int total = 0;
    stack<int> s;

    cin >> k;

    for(int i = 0 ; i < k ; i++){
        int input;
        cin >> input;

        if(input == 0){
            s.pop();
        }else{
            s.push(input);
        }
    }
    
    while(!s.empty()){
        total += s.top();
        s.pop();
    }

    cout << total;


    return 0;
}
