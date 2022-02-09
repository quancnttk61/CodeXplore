#include <iostream>
using namespace std;

class MyDate{
    protected:
        int day,month,year;
    public:
        MyDate(){
            day = 1;
            month = 1;
            year = 1;
        }
        void Enter();
        bool operator > (MyDate &b);
        void print();
};


void MyDate::Enter(){
    fflush(stdin);
    cout <<"Date: ";
    cin >> day;
    cin >> month;
    cin >> year;
}

void MyDate::print(){
    cout <<"Date: "<< day <<"//"<< month <<"//"<< year << endl;
}

bool MyDate::operator > (MyDate &a){
    if(year > a.year) 
        return true;
    else if(year == a.year) {
        if(month > a.month) 
            return true;
        else if(month == a.month) {
            if(day > a.day) 
                return true;
            else if(day == a.day) 
                return true;
        }
    }
    else
        return false;
}

class Person : public MyDate{
    protected:
        string name,addr;
        int phone;
    public: 
        Person(){
            name = " ";
            addr = " ";
            phone = 0;
        }
        void Enter();
        void Show();
};

void Person::Enter(){
    fflush(stdin);
    cout << "Name: ";
    getline(cin,name);
    cout << "Address: ";
    getline (cin,addr);
    cout << "Phone: ";
    cin >> phone;
    MyDate::Enter();
}

void Person::Show(){
    cout << "Name: "<< name <<"|| Address: "<< addr <<endl;
    cout << "Phone: "<< phone << endl;
    MyDate::print();
}

class Officer : public Person{
        float salary;
    public:
        Officer(){
            salary = 0;
        }
        void Enter();
        void Show();
};

void Officer::Enter(){
    Person::Enter();
    cout << "Salary: ";
    cin >> salary;
}

void Officer::Show(){
    Person::Show();
    cout << "Salary: "<< salary <<endl;
}
int main(){
    Officer *of = new Officer;
    for ( int i = 0; i < 4; i++){
        of[i].Enter();
    }
    for ( int i = 0; i < 4; i++){
        of[i].Show();
    }
    return 0;
}
