#include <iostream>

using namespace std;

class Cents{
private:
    int m_value;
public:
    Cents(int inputV)
        :m_value{inputV}{}

    int getValue() const {
        return m_value;
    }

    int& getValue(){ //overloading 
        return m_value;
    }
    
    
};

std::ostream& operator >>(std::ostream& out,const Cents& cents ){
    
}

int main(){


    return 0;
}