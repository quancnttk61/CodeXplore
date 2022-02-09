//Nguyen Minh Quan - 6151071087
#include<iostream>
using namespace std;
 
class Complex{
    private:
        float a; 
        float b; 
    public:
        Complex();
        ~Complex();
        void input();
        void in();
        friend Complex operator +(Complex &a,Complex &b);
        void operator =(Complex a);
};
Complex::Complex(){
    this->a=0;
    this->b=0;
}
Complex::~Complex(){}
void Complex::input(){
    cout<<endl<<"Enter phan thuc: "; cin>>a;
    cout<<endl<<"Enter phan ao: "; cin>>b;
}
void Complex::in(){
    cout<<a<<"+"<<b<<"i"<<endl;
}
Complex operator+(Complex &a,Complex &b){
    Complex c;
    c.a=a.a+b.a;
    c.b=a.b+b.b;
    return c;
}
void Complex::operator=(Complex a){
    this->a = a.a;
    this->b = a.b;
}
int main(){
    int n;
    cout<<endl<<"Enter n: "; cin>>n;
    Complex a[n];
    for(int i=0;i<n;i++){
        cout<<endl<<"Complex "<<i<<endl;
        a[i].input();
    }
    Complex sum;
    for(int i=0;i<n;i++){
        sum = sum + a[i];
    }
    cout<<endl<<"Sum: ";
    sum.in();
    return 0;
}
