#include <iostream>
#include <array>
#include <functional>

using namespace std;

// typedef bool (*checkPtr)(int); //하나의 type으로 규정

bool isOdd(int num){
    if(num % 2 != 0)
        return true;
    else
        return false;
}

bool isEven(int num){
    if(num % 2 == 0)
        return true;
    else
        return false;
}

void printElement(std::array<int,10> arr,std::function<bool(const int&)> check_ptr){
    for(const auto& c:arr ){
        if(check_ptr(c)){
            cout << c << " ";
        }
    }
}


int main(){
    std::array<int,10> arr{0,1,2,3,4,5,6,7,8,9};
    std::function< bool (const int&)> check;

    check = isEven;

    printElement(arr,isEven);

    cout << endl;

    check = isOdd;
    
    printElement(arr,isOdd);

    return 0;

}