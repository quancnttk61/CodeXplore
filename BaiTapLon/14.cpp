// Nguyen Minh Quan 6151071087
#include <iostream>

using namespace std;

class MyDate
{
    private:
        int day, month, year;
    public:
        MyDate();
        MyDate(int day, int month, int year);
        MyDate(const int a);
        void Nhap();
        void printf();
        bool operator ==(MyDate mydate);
        int getYear();
        int getMonth();
        int getDay();
};
MyDate::MyDate()
{
    this->day = 20;
    this->month = 1;
    this->year = 2002;
}
MyDate::MyDate(int ngay, int thang, int nam)
{
    this->day = ngay;
    this->month = thang;
    this->year = nam;
}
MyDate::MyDate(const int a)
{
    this->day = this->month = this->year = a;
}
void MyDate::Nhap()
{
    cout<<"Enter day"<<endl;
	 cin>>day;
    cout<<"Enter mouth: "<<endl;
	 cin>>month;
    cout<<"Enter year "<<endl;
	 cin>>year;
}
void MyDate::printf()
{
    cout<<day<<" / "<<month<<" / "<<year;
}
bool MyDate::operator ==(MyDate mydate)
{
    if((this->year == mydate.year) && (this->month == mydate.month) && (this->day == mydate.day)) 
        return true;
    return false;
}
int MyDate::getDay()
{
    return this->day;
}
int MyDate::getMonth()
{
    return this->month;
}
int MyDate::getYear()
{
    return this->year;
}
int main()
{
    MyDate a[12], x;

    for(int i = 0; i < 2; i++)
    {
        cout<<"Enter Day , Mouth and Year of MyDate"<<i + 1<<": "<<endl;
        a[i].Enter();
    }
    
    for(int i = 0; i < 5; i++)
    {
        cout<<"MyDate "<<i + 1<<": "<<endl;
        a[i].printf(); 
    }

    cout<<"Enter MyDate for sreach: ";
    x.Enter();
    int dem = 0;
    for(int i = 0; i < 5; i++) 
    {
        if (a[i] == x) 
        {
            dem++;
            cout<< x.printf(); cout<<" found"<<" time: "<<dem<<endl; 
        } 
    }
    if(dem == 0)
        { 
            cout<<"not found"<<x.printf() ; 
        }

 return 0;
}
