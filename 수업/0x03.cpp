#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    int target = idx;
    
    if(target == len){
        arr[target] = num;
    }else{
        for(int i = len; i > target ;i--){
            arr[i] = arr[i-1]; //이전의 값 복사
        }

        arr[target] = num;
    }

    len++;
}

void erase(int idx, int arr[], int& len){
    int target = idx;

    if(target == len){
        len--;
    }else{
        for(int i = target ; i < len ;i++){
            arr[i] = arr[i+1];
        }
        len--;
    }

}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}

//배열 초기화

int a[21];
int b[21][21];

//1.memset
memset(a,0,sizeof a);
memset(b,0,sizeof b);

//2. for로 직접 채우기

for(int i = 0 ; i < 21 ; i++)
    a[i] = 0;
for(int i = 0 ; i < 21 ; i++)
    for(int j = 0; j < 21 ; j++)
        b[i][j] = 0;

//3. fill
fill(a,a+21,0);
for(int i = 0 ; i < 21 ; i++)
    fill(b[i],b[i]+21,0)
