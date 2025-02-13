#include <bits/stdc++.h>

using namespace std;

void NGE(int index,vector<int>& input,int n){
    vector<int> v;

    v.push_back(input[index]);

    for(int i = index + 1 ; i < n ; i++ ){
        if(v[0] < input[i]){
            
            if(v.size() == 2 && input[i] < input[0]){
                v.pop_back();
                v.push_back(input[i]);
                continue;
            }

            v.push_back(input[i]);
        }


    }

    if(v.size() < 2){
        cout << -1 << " ";
    }else{
        cout << v[1] << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input;
    
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    for(int i = 0; i < n ; i++){
        NGE(i,input,n);
    }

    return 0;
}