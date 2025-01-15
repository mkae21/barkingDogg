#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxValue = 0;
    int maxIndex = 0;
    int n;

    for(int i = 0 ; i < 9 ; i++){
        cin >> n;

        if(maxValue < n){
            maxValue = n;
            maxIndex = i;
        }
    } 

    cout << maxValue <<"\n" << maxIndex+1;
}