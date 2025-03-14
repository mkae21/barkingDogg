
#include <bits/stdc++.h>
using namespace std;

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  stack<int> S;
  
  int cnt = 1;
  string ans;
  
  while (n--) {
    int t;
    cin >> t; //목표 숫자
    
    while (cnt <= t) {
      S.push(cnt++);
      ans += "+\n"; // string에 일반연산 가능하구나..
    }
    
    if (S.top() != t) {
      cout << "NO\n";
      return 0;
    }
    
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}

/*
현재 처리를 필요로 하는 수는 cnt이다. cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가
될 때 까지 push를 해야 한다(18-21줄). 만약 22번째 줄과 같이 S.top()과 t가 일치하지 않는다면
올바르지 않은 수열이다.
*/