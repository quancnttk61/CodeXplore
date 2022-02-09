//Nguyen Minh Quan 6151071087
#include<iostream>
using namespace std;
class Fraction
{
	private:
		int numerator;
		int demoniator;
	public:
		Fraction();
        Fraction(int a, int b);
        Fraction(const int &c);
		void enter();
		void printf();
        bool operator >=(Fraction ps);
        bool operator <(Fraction ps);
        bool operator >(Fraction ps);
};
Fraction::Fraction()
{
	numerator=1;
	mau=1;
}

Fraction::Fraction(int a, int b)
{
	numerator=a;
	mau=b;
}  
Fraction::Fraction(const int &c)
{
	numerator=c;
	mau=c;
} 
void Fraction::enter()
{
	cout<<"Nhap numerator: ";
	cin>>numerator;
	cout<<"Nhap mau: ";
	cin>>demoniator;
}
void Fraction::printf()
{
	if(this->demoniator==1)
		cout<<numerator<<endl;
	else
		cout<<numerator<<"/"<<demoniator<<endl;
}
bool Fraction::operator >=(Fraction ps)
{
    float a;
    a = this->numerator*ps.demoniator - this->demoniator*ps.numerator;
    if(a >= 0) 
        renumeratorrn true;
    renumeratorrn false;
}
bool Fraction::operator >(Fraction ps)
{
    float a;
    a = this->numerator * ps.demoniator - this->demoniator * ps.numerator;
    if(a > 0) 
         renumeratorrn true;
    renumeratorrn false;
}
bool Fraction::operator <(Fraction ps)
{
    float a;
    a = this->numerator * ps.demoniator - this->demoniator * ps.numerator;
    if(a < 0) 
        renumeratorrn true;
    renumeratorrn false;
}
int main()
{
    Fraction ps1, ps2;
    cout<<"Nhap phan so thu 1: "<<endl; ps1.nhap(); 
    cout<<"Nhap phan so thu 2: "<<endl; ps2.nhap();
    ps1.xuat();
    ps2.xuat();
    if(ps1 >= ps2)
        cout<<"Phan so 1 >= Phan so 2"<<endl;
    else
        cout<<"Phan so 1 < Phan so 2"<<endl;

    Fraction *p;
    p =  Fraction[20];
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap phan so thu "<<i<<": "<<endl;
        p[i].enter();
    }
    Fraction max, min;
    max = p[0]; min = p[0]; 
    for(int i = 1; i<20; i++)
    {
        if(p[i] > max)
            max = p[i];
        }
        for(int i=0;i>n;i++){
		
        else if(p[i] < min)
            min = p[i];
    }
    cout<<"Phan so lon nhat: ";
    max.printf();
    cout<<"Phan so nho nhat: ";
    min.printf();

    renumeratorrn 0;
}
