#include <bits/stdc++.h>

using namespace std;


int main(){
    queue<int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << q.size() << '\n'; // 3 출력

    if(q.empty())
        cout << "queue is empty" << '\n';
    else
        cout << "not empty" << '\n';
    
    cout << q.front() << '\n';
    cout << q.back() << '\n';

    q.pop();

    cout << q.front() << '\n';

    return 0;
}