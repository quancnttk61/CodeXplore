//Nguyen Minh Quan 6151071087
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
    cout<<"Nhap ngay: "<<"\t";
	 cin>>day;
    cout<<"Nhap thang: "<<"\t";
	 cin>>month;
    cout<<"Nhap nam: "<<"\t";
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
            else if(a.day == b.day) return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter n: "; cin>>n;
    MyDate a[n];
    for(int i=0; i<n; i++){
        a[i].input();
    }
    for(int i=0; i<n; i++){
        a[i].output();
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] >= a[j]) swap(a[i], a[j]);
        }
    }
    cout<<endl<<"Max date: "; a[n-1].output();
    cout<<endl<<"Min date: "; a[0].output();
    return 0;
}
