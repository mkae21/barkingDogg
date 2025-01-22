#include <bits/stdc++.h>

using namespace std;

// void commandL(list<char>& list,list<char>::iterator &cursor){
//     --cursor;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;

    list<char> L;
    string input;
    
    cin >> input;

    for(auto c : input) //다른 초기화 방법?
        L.push_back(c);
    
    //커서 초기화
    list<char>::iterator cursor = L.end(); //cursor
    cin >>  N; //명령어 갯수

    for(int i = 0; i < N ; i++){
        char temp;
        cin >> temp;

        if(temp == 'L'){
            if(cursor != L.begin())
                cursor--;
        }else if(temp == 'D'){
            if(cursor != L.end())
                cursor++;
        }else if(temp == 'B'){
            if(cursor != L.begin()){
                cursor = L.erase(--cursor);
            }
        }else{//추가
            cin >> temp;
            L.insert(cursor,temp);
        }

    }

    for(auto c: L)
        cout << c;

    return 0;
}