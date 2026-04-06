#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000005]; //원본 저장
std::vector<int> uni;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
        uni.push_back(arr[i]);
    }

    //정렬
    sort(uni.begin(),uni.end());

    //중복 제거
    uni.erase(unique(uni.begin(),uni.end()),uni.end());
    
    for(int i = 0 ; i < n ; i++)
        cout << lower_bound(uni.begin(),uni.end(),arr[i]) - uni.begin() << " ";
        
    return 0;
}