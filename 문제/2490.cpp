#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);// stdio와 iostream의 동기화 끊기
    cin.tie(0); // 출력 버퍼 비우기 비활성화
    
    vector<vector<int>> matrix;
    string line;

    int cnt = 3;
    int num;
    int i =0;
    
    while(cnt--){ // 입력 받은 라인으로 2차원 배열 생성하기
        vector<int> row; //초기화 필수

        getline(cin,line);
        stringstream ss(line); // 문자열을 공백 기준으로 split

        while(ss >> num){
            row.push_back(num);
        }
        matrix.push_back(row); //2차원 배열에 삽입
    }

    for(int i = 0 ; i < 3 ; i++){

        int flag = 0;

        for(int j = 0 ;j < 4 ; j++){
            if(matrix[i][j] == 1){ // 1일 때 
                flag++;
            }
        }

        switch(flag){
            case 0: //윷
                cout << "D\n";
                break;
            case 1: // 걸
                cout << "C\n";
                break;
            case 2: // 개
                cout << "B\n";
                break;
            case 3: // 도
                cout << "A\n";
                break;
            case 4: // 모
                cout << "E\n";
                break;
            default:
                break;
        }

    }


    return 0;
}