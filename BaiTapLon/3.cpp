//Nguyen Minh Quan  6151071087
#include<iostream>
using namespace std;
 
class MyDate{
    private:
        int day,month,year;
    public:
        MyDate();
        ~MyDate();
        void input();
        void output();
        friend bool operator >=(MyDate &a, MyDate &b);
};
MyDate::MyDate(){
    this->day =0;
    this->month =0;
    this->year =0;
}
MyDate::~MyDate(){}
void MyDate::input(){
    cout<<"enter day: "<<endl;
	cin>>day;
    cout<<"enter month: "<<endl;
	cin>>month;
    cout<<"\nenter year: "<<endl;
	cin>>year;
}
void MyDate::output(){
    cout<<endl<<day<<"-"<<month<<"-"<<year;
}
bool operator >=(MyDate &a, MyDate &b){
    if(a.year >b.year) return true;
    else if(a.year == b.year) {
        if(a.month >b.month) return true;
        else if(a.month == b.month) {
            if(a.day >b.day) return true;
            if(a.day == b.day) return true;
        }
    }
    return false;
}
int main(){
    MyDate a[20];
    for(int i=0; i<20; i++){
        a[i].input();
    }
    for(int i=0; i<20; i++){
        a[i].output();
    }
    MyDate b;
    for(int i=0; i<20;i++){
        if(a[i] >= b){
            b = a[i];
        }
    }
    cout<<endl<<"Max date: ";
    b.output();
    return 0;
}


