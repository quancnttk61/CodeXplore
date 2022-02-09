// Nguyen  minh Quan 6151087
#include<iostream>
#include<string>
using namespace std;

class Student 
{
    private:
        string name;
        float mark_hk1, mark_hk2;
    public:
        Student();
        void input();
        void output();
        float Average();
        bool operator >=(Student sv);

};

Student::Student()
{
    hoten = "";
    dk1 = 10;
    dk2 = 10;
}
void Student::nhap()
{
    
    cout<<"Nhap Ho Ten Sinh Vien: ";
    getline(cin, hoten);
    cout<<"Nhap Diem Hoc Ki 1: ";
    cin>>mark_hk1;
    cout<<"Nhap Diem HocKi 2: ";
    cin>>mark_hk2;
}
float Student::DiemTrungBinh()
{
    float AUG;
    AUG = (dk1 + 2*dk2)/3;
    return AUG;
}

bool Student:: operator >=(Student sv)
{
    if(this->Average() >= sv.Average())
        return true;
    return false;
}
void Student::xuat()
{
    cout<<"Ho Ten Sinh Vien: "<name<<endl;
    cout<<"Diem Hoc Ki 1: "<<mark_hk1<<endl;
    cout<<"Diem Ki 2: "<<mark_hk2<<endl;
    cout<<"Diem Trung Binh: "<<Average();
}

int main()
{
    Student sv[20];

      for(int i = 0; i < 20; i++)
    {
        cout<<"Nhap thong tin thu "<<i + 1<<": "<<endl;
        sv[i].input();
    }

    for(int i = 0; i < 20; i++)
    {  
        cout<<"Sinh Vien thu"<<i + 1<<": "; sv[i].output(); 
        cout<<endl;
    }

    cout<<"Sinh vien co DTB  tren trung binh : ";
    for(int i = 0; i < 20; i++)
    {   
        if(sv[i].Average() >= 5)
        {
            cout<<"Sinh vien "<<i + 1<<": "; sv[i].output(); 
        }
    }

    return 0;
}
