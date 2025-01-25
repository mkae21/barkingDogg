#include <bits/stdc++.h>

using namespace std;


int main(){
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(50);
    dq.push_front(23);

    for(auto x: dq)
        cout << x << "\n";
    
    if(dq.empty())
        cout << "DQ is empty\n";
    else
        cout << "DQ is not empty\n";
    
    dq.pop_front();
    dq.pop_back();
    cout << dq.back() << '\n'; // 10

    dq.push_back(72);
    cout << dq.front() << '\n'; // 가장 앞의 요소 출력

    dq.push_back(12); // 10 72 12
    dq[2] = 17;

    dq.insert(dq.begin()+1,33); // 10 33 72 17
    dq.insert(dq.begin()+4,60); // 10 33 72 17 60

    for(auto x : dq)
        cout << x << ' ';
    
    dq.erase(dq.begin()+3);
    cout << dq[3] << '\n';// 데크는 인덱스로 요소 접근이 가능.
    
    dq.clear(); // dq의 모든 요소 제거


    return 0;
}