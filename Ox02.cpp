#include <iostream>

using namespace std;

void func1(){ //무한 loop
    for(char s = 0 ; s < 128 ; s++){
        cout << "hi";
    }
}

int func2(){
    int r = 1;
    for(int i = 1; i <= 50; i++){
        r = r*i % 61;
    }
    return r;
}

int func3(){
    int a = 10;
    int mod = 1000000007;
    for(int i = 0 ; i < 10 ; i++)
        a = 10 * a % mod;
    return a;
}

int main(){


    return 0;
}