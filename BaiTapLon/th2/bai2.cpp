#include<iostream>
using namespace std;

class Complex{
    private:
        float a; //
        float b; 
    public:
        Complex(float p,float q);
        ~Complex();
        void input();
        void output();
        friend Complex operator +(Complex &a,Complex &b);
        friend Complex operator *(Complex &a,Complex &b);
        
};
Complex::Complex(float p,float q){
    this->a=p;
    this->b=q;
}
Complex::~Complex(){}
void Complex::input(){
    cout<<endl<<"Enter real part: ";cin>>a;
    cout<<endl<<"Enter imag part: ";cin>>b;
}
void Complex::output(){
    cout<<"Complex: "<<a<<"+"<<b<<"i"<<endl;
}
Complex operator+(Complex &a,Complex &b){
    Complex c;
    c.a=a.a+b.a;
    c.b=a.b+b.b;
    return c;
}
Complex operator *(Complex &a,Complex &b){
 	Complex c;
 	c.a=a.a*b.a
 	c.b=a.b*b.b;
 	return c;
 }
int main(){
    Complex a,b,c,d,m,n,S;
    a.input();
    b.input();
    c.input();
    d.input()
    (c+d)=n;
    (a+b)=m;
    S=m*n;
  cout<<"S=(a+b)*(c+d)"<<S.output();
    return 0;
}
