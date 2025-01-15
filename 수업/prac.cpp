#include <bits/stdc++.h>

using namespace std;
int numbers[100];

int func2(int* arr, int size){
    int occur[101] = {};
    
    for(int i = 0 ; i < size ; i++){
        if(occur[100-arr[i]] == 1)
            return 1;
        occur[arr[i]] = 1;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3] = {1,52,48};

    cout << func2(arr,3);

}