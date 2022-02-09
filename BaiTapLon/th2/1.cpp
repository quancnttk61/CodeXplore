#include <iostream>
using namespace std;

class MyAttr{
    protected:
        int x;
    public:
        MyAttr(){
            x = 0;
        }
        void Enter();
        void print();
};

class MyDate{
    protected:
        int day,month,year;
    public:
        MyDate(){
            day = 1;
            month = 1;
            year = 1;
        }
        void EnterD();
        bool operator > (MyDate &b);
        void printD();
};

class Myfile : public MyDate , public MyAttr{
        string name;
        int size;
    public:
        void EnterF();
        void printFile();
};

void MyAttr::Enter(){
    fflush(stdin);
    cout << "Enter subtraction: ";
    cin >> x;
}

void MyAttr::print(){
    cout << "Subtraction: "<< x <<endl;
}


void MyDate::EnterD(){
    fflush(stdin);
    cout <<"Date: ";
    cin >> day;
    cin >> month;
    cin >> year;
}

void MyDate::printD(){
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

void Myfile::EnterF(){
    MyAttr::Enter();
    MyDate::EnterD();
    fflush(stdin);
    cout <<"File name: ";
    getline(cin,name);
    cout <<"Size: ";
    cin >> size;
}

void Myfile::printFile(){
    MyAttr::print();
    MyDate::printD();
    cout <<"File name: "<< name <<endl;
    cout <<"Size: "<< size <<endl;
}

int main(){
    Myfile *mf = new Myfile[4];
    for(int i = 0; i < 4; i++){
        cout <<"-------"<<endl;
        mf[i].EnterF();
    }
    for(int i = 0; i < 4; i++){
        mf[i].printFile();
        cout <<"-------"<<endl;
    }
    delete [] mf;
    return 0;
}
