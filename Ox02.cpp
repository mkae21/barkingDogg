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

    vector<int> v(100); // 0으로 초기화
    func1(v);
    cout << v[10];
}


