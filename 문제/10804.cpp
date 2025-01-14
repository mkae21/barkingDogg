#include <bits/stdc++.h>

using namespace std;

void reverse(int* num,int a, int b){
    for(int i = 0; i< (b-a + 1) / 2 ; i++)
        swap(num[a+i],num[b-i]);
}

int main(){

    int num[21];

    for(int i = 1 ; i <= 20; i++) // 초기화
        num[i] = i;

    for(int i = 1 ; i <= 10 ; i++){
        int a,b;
        cin >> a >> b;
        reverse(num+a,num+b+1);//끝을 가리키는 반복자.
    }

    for(int i = 1 ; i<= 20 ; i++)
        cout << num[i] << ' ';

    return 0;
}
