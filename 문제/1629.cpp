#include <iostream>
//제한 시간 0.5초 : 50000번
using namespace std;
using ll = long long;
//자연수 a^b % c

ll mod_func(ll a, ll b, ll c){
    
    //k = 1일 때
    if(b == 1)
        return a % c;
    
    //b가 1에 수렴하도록
    ll val = mod_func(a,b/2,c);
    val = val * val % c;
    //b = 2k일때 -> 짝수 제곱
    if(b % 2 == 0)
        return val;
    //b = 2k + 1 -> 홀수 제곱
    return val * a % c; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;

    ll result  = mod_func(a,b,c);
    cout << result;
    return 0;
}