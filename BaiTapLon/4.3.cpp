#include <iostream>
using namespace std;


class Fration
{
    private:
        float a, b;
    public:
        Fratcion();
        Fratcion(float a, float b);
        void input();
        void display();
        void compact();
        Fratcion operator+(Fratcion f);
        Fratcion operator=(Fratcion f);
};
Fratcion::Fratcion()
{
    this->a = 0;
    this->b = 1;
}
Fratcion::Fratcion(float a, float b)
{
    this->a = a;
    this->b = b;
}
void Fratcion::input()
{
    cout << "\nNhap tu: " <<endl; cin >> a;
    do{
        cout << "\nNhap mau: "<<endl; cin >> b;
        if(b == 0)
            cout<<"Mau phai khac 0!!!"<<endl;
    }while(b == 0);
}
void Fratcion::display()
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
void Fratcion::compact()
{
    int greatest_common_divisor = greatestCommonDivisor(a, b);
    a = a / greatest_common_divisor;
    b = b / greatest_common_divisor; 
}
Fratcion Fratcion::operator+(Fratcion f)
{
    return Fratcion((this->a * f.b) + (this->b * f.a), this->b * f.b);
}
Fratcion Fratcion::operator=(Fratcion f)
{
    this->a = f.a;
    this->b = f.b;
    return *this;
}
int main()
{ 
    int num, n2;
    int fl[n2];
    input2(fl, n2);
    display2(fl, n2);
    Fratcion *frac = new Fratcion[num];
    Fratcion t;
    cout<<"Enter num Fratcion number: "<<endl;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Enter frac "<<i+1<<endl;
        frac[i].input();
        t = t + frac[i];
    }
    cout<<"Fratcion sum is: "<<endl;
    t.display();
    Fratcion a(4,5), b(5,4);
    cout<<"Assigned: "<<endl;
    a = b;
    a.display();
    system("pause");
}
void input2(int fl[], int &n2)
{
    cout<<"Enter num int number: "<<endl;
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        cout<<"Enter elements "<<i+1<<":"<<endl;
        cin>>fl[i];
    }
}
void display2(int fl[], int num0)
{
    float max = sum(fl, num0);
    cout<<"Integer sum is: "<<max<<endl;
}
int sum(int fl[], int num0)
{
    int sum = 0;
    for(int i=0; i<num0; i++)
        sum += fl[i];
    return sum;
}
