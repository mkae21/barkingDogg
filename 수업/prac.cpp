#include <bits/stdc++.h>

using namespace std;

int main(){

    list<int> L = {1,2}; // 연결리스트 선언
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중

    L.push_front(10);  // 10 1 2
    cout << *t << '\n';

    L.push_back(5);// 10 1 2 5
    L.insert(t,6);// t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++; //다음 원소

    t = L.erase(t); // erase()는 t가 가리키는 값을 제거 후 그 다음 원소인 5의 위치를 반환
                    // 10 6 1 5,t 가 가리키는 값은 5
                    // 링크드 리스트의 삭제와 동일하다

    cout << *t << '\n';

    for(auto i:L) // cpp 11 이상
        cout << i <<' ';

    cout << '\n';

    for(list<int>::iterator it = L.begin();it != L.end();it++){ //cpp 11 미만
        cout << *it << ' ';
    }

    return 0;
}