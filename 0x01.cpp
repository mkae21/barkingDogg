#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int func1(int num){ //시간 복잡도 O(N)
    int total = 0;
    for(int i = 0; i <= num ; i++){
        if(i % 5 == 0 or i % 3 == 0)
            total += i;
    }
    return total;
}

//다른 원소 두개를 더 했을때 100이되는 조합이 있으면 1, 없으면 0
int func2(int arr[],int length){
    for(int i =0;i<length ; i++){
        for(int j = i+1; j < length; j++){
            if (arr[i] + arr[j] == 100)
                return 1;
            else
                continue;
        }
    }
    return 0;
}

int func3(int n){
    for(int i = 1 ; i <= n ; i++){
        if(i*i == n)
            return 1;
    }
    return 0;
}

int func4(int n){
    int max;
    for(int i = 1; 2*i <= n ;i++){
        max = 2*i;
    }
    return max;
}

int func4_(int n){
    int val = 1;
    while(2*val <= n)
        val *=2;
    return val;
}

int main(){
    int result = 0;
    int num = 0;

    cin >> num;
    result = func4(num);

    cout<< result;
    return 0;
}