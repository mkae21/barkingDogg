#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void func1(vector<int> v){
    v[10] = 7;
}

bool compare(vector<int> v1,vector<int> v2, int idx){
    return v1[idx] > v2[idx];
}

bool compare2(vector<int>& v1,vector<int>& v2, int idx){
    return v1[idx] > v2[idx];
}

int main(){
    /* 
    입력

    14 104
    2 5
    94 542
    */

    for(int i = 0;i<3; i++){
        int a,b;
        cin >> a >> b;
        cout << a+b << '\n';
    }

}


