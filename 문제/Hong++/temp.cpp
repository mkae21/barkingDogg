#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient{
private:
    string m_name;
    std::vector<Doctor*> m_doctors; 
public:
    Patient(string name_in)
        :m_name(name_in){}
};

class Doctor{
private:
    string m_name;
public:
    Doctor(string name_in)
        :m_name{name_in}{}
};

int main(){
    Patient* p1 = new Patient("Jack Jack");
    Patient* p2 = new Patient("Dash");
    Patient* p3 = new Patient("Violet");

    Doctor* d1 = new Doctor("Doctor K");
    Doctor* d2 = new Doctor("Doctor L");

    //patients meet doctors


    //doctors meet patients


    //deletes
    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0;
}