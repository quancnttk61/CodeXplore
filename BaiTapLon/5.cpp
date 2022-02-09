//Nguyen Minh Quan 6151071087
#include <iostream>
using namespace std;
class Fraction{
    private:
        float numerator;
        float denominator;
    public:
        Fraction();
        ~Fraction();
        Fraction(float a, float b);
        friend istream& operator>>(istream& is, Fraction& fraction);
        friend float UCLN(float a, float b);
        friend Fraction RUTGON(Fraction &fraction);
        Fraction operator+(Fraction a);
        Fraction operator-(Fraction a);
        Fraction operator*(Fraction a);
        Fraction operator/(Fraction a);
        friend ostream& operator<<(ostream& os, Fraction fraction);
};
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(float a, float b){
    numerator = a;
    denominator = b;
}
Fraction::~Fraction(){}
istream& operator>>(istream& is, Fraction& fraction){
    cout<<"Enter numerator: ";
    is>>fraction.numerator;
    do{
    cout<<"Enter denominator: ";
    is>>fraction.denominator;
    }while(fraction.denominator == 0);
    return is;
}
ostream& operator<<(ostream& os, Fraction fraction){
    os<<fraction.numerator<< "/" <<fraction.denominator<<endl;
    return os;
}
void input(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Enter fraction "<<i<<": "<<endl;
        cin>>a[i];
    }
}
float UNLC(float a, float b)
{

    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
Fraction RUTGON(Fraction &fraction)
{
    float c = UCLN(fraction.numerator, fraction.denominator);
    fraction.numerator = fraction.numerator / c;
    fraction.denominator = fraction.denominator / c;
    return fraction;
}
Fraction Fraction::operator+(Fraction a){
    Fraction b = ((numerator*a.denominator) + (denominator*a.numerator),denominator*a.denominator);
    return RUTGON(b);
}
Fraction Fraction::operator-(Fraction a){
    Fraction b = ((numerator*a.denominator) - (denominator*a.numerator),denominator*a.denominator);
    return RUTGON(b);
}
Fraction Fraction::operator*(Fraction a){
    Fraction b = (numerator*a.numerator,denominator*a.denominator);
    return RUTGON(b);
}
Fraction Fraction::operator/(Fraction a){
    Fraction b = (numerator*a.denominator,denominator*a.numerator);
    return RUTGON(b);
}
void output(Fraction a[], int n){
    Fraction sum;
    for(int i=0; i<n;i++){
        sum = sum + a[i];
    }
    cout<<"Sum: "<<sum<<endl;
}
int main(){
	int n;
    Fraction a, b;
	 cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<"Enter n: ";  cin>>n;
    Fraction list[n];
    input(list,n);
    output(list, n);
}
