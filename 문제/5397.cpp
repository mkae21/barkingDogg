#include <bits/stdc++.h>

using namespace std;

void handleCommand(char c,list<int>& inputCase,list<int>::iterator& t){
    if(c == '<'){//가장 왼쪽 일 때 무시
        if(t != inputCase.begin()){
            t--;
        }
    }else if(c == '>'){//가장 오른쪽 일 때 무시
        if(t != inputCase.end())
            t++;
    }else if(c == '-'){
        if(t != inputCase.begin())
            t = inputCase.erase(--t); //커서가 앞 글자를 지운다.
    }else{
        inputCase.insert(t,c);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input; //입력
        
        list<int> inputCase;
        auto t = inputCase.end();

        for(auto c : input){ //여기서 명령어 처리
            handleCommand(c,inputCase,t);
        }

        for(char c: inputCase)
            cout << c;

        cout << '\n';
    }


    return 0;
}