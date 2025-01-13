#include <bits/stdc++.h>

using namespace std;

int main(){

    vector <int> val;
    int temp;

    for(int i = 0 ; i < 5 ; i++){
        cin >> temp;
        val.push_back(temp);
    }

    sort(val.begin(),val.end());
    
    cout << accumulate(val.begin(),val.end(),0) / val.size() << "\n";
    cout << val[val.size()/2];

    return 0;
}