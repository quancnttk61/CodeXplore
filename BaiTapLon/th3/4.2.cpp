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
        bool operator>(Fraction f);
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
    cout <<endl<< Enter numerator: " <<endl; cin >> a;
    do{
        cout << "\nEnter demominator: "<<endl; cin >> b;
        if(b == 0)
            cout<<"Demominator must not equal 0!"<<endl;
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
bool Fraction::operator>(Fraction f)
{
    float gt1 = this->a / this->b;
    float gt2 = f.a / f.b;
    return (gt1>gt2)?true:false;
}
Fraction Fraction::operator=(Fraction f)
{
    this->a = f.a;
    this->b = f.b;
    return *this;
}

void input2(float fl[], int &n2)
{
    cout<<"Enter number of float number: "<<endl;
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        cout<<"Enter elements "<<i+1<<":"<<endl;
        cin>>fl[i];
    }
}
float findMax2(float fl[], int n2)
{
    float max = fl[0];
    for(int i=1; i<n2; i++)
        if(fl[i] > max)
            max = fl[i];
    return max;
}
void display2(float fl[], int n2)
{
    float max = findMax2(fl, n2);
    cout<<"Max float number is: "<<max<<endl;
}
int main()
{ 
    int n, n2;
    float fl[n2];
    input2(fl, n2);
    display2(fl, n2);
    Fraction *frac = new Fraction[n];
    cout<<"Enter number of Fraction number: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter frac "<<i+1<<endl;
        frac[i].input();
    }
    cout<<"Fraction max: "<<endl;
    Fraction max = frac[0];
    for(int i=1; i<n; i++)
        if(frac[i]>max)
            max = frac[i];
    max.display();
    Fraction a(4,5), b(5,4);
    cout<<"Assigned: "<<endl;
    a = b;
    a.display();
}
