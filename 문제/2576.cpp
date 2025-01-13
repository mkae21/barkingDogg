#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> value;
    int num;
    int total=0;

    for(int i = 0 ; i < 7 ; i++){
        cin >> num;
        if(num % 2 != 0){
            value.push_back(num);
            total += num;
        }
    }

    if(value.empty())
        cout << -1;
    else{
        // cout << accumulate(value.begin(),value.end(),0) << "\n";
        cout << total << "\n";
        int temp = *min_element(value.begin(),value.end());
        cout << temp;
    }


    return 0;
}