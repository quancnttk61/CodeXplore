// Nguyen Minh Quan 6151071087
#include <iostream>
using namespace std;


class Fraction
{
    private:
        float a, b;
    public:
        Fraction();
        Fraction(float a, float b);
        void input();
        void display();
        void compact();
        Fraction operator+(Fraction f);
        Fraction operator=(Fraction f);
};
Fraction::Fraction()
{
    this->a = 0;
    this->b = 1;
}
Fraction::Fraction(float a, float b)
{
    this->a = a;
    this->b = b;
}
void Fraction::input()
{
    cout << "\nNhap tu: " <<endl; cin >> a;
    do{
        cout << "\nNhap mau: "<<endl; cin >> b;
        if(b == 0)
            cout<<"Mau phai khac 0!!!"<<endl;
    }while(b == 0);
}
void Fraction::display()
{
    compact();
    if(a == 0 || b == 1)
        cout<<a<<endl;
    else cout<<a<<"/"<<b<<endl;
}
int greatestCommonDivisor(int number1, int number2)
{
    if (number2 == 0) return number1;
    return greatestCommonDivisor(number2, number1 % number2);
}
void Fraction::compact()
{
    int greatest_common_divisor = greatestCommonDivisor(a, b);
    a = a / greatest_common_divisor;
    b = b / greatest_common_divisor; 
}
Fraction Fraction::operator+(Fraction f)
{
    return Fraction((this->a * f.b) + (this->b * f.a), this->b * f.b);
}
Fraction Fraction::operator=(Fraction f)
{
    this->a = f.a;
    this->b = f.b;
    return *this;
}
int main()
{ 
    int n, n2;
    int fl[n2];
    input2(fl, n2);
    display2(fl, n2);
    Fraction *frac = new Fraction[n];
    Fraction t;
    cout<<"Enter n Fraction number: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter frac "<<i+1<<endl;
        frac[i].input();
        t = t + frac[i];
    }
    cout<<"Fraction sum is: "<<endl;
    t.display();
    Fraction a(4,5), b(5,4);
    cout<<"Assigned: "<<endl;
    a = b;
    a.display();
    system("pause");
}
void input2(int fl[], int &n2)
{
    cout<<"Enter n int number: "<<endl;
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        cout<<"Enter elements "<<i+1<<":"<<endl;
        cin>>fl[i];
    }
}
void display2(int fl[], int n2)
{
    float max = sum(fl, n2);
    cout<<"Integer sum is: "<<max<<endl;
}
int sum(int fl[], int n2)
{
    int sum = 0;
    for(int i=0; i<n2; i++)
        sum += fl[i];
    return sum;
}

