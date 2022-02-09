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
        friend istream& operator>>(istream& is, Fraction& fraction);
        friend ostream& operator<<(ostream& os, Fraction fraction);
        bool operator >(Fraction p);
};
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
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
bool Fraction::operator >(Fraction p){
    return ((float)(this->numerator)/this->denominator > p.numerator/p.denominator);
}
void input(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Enter fraction "<<i<<": "<<endl;
        cin>>a[i];
    }
}
void output(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Fraction "<<i<<": ";
        cout<<a[i];
    }
}
void sort(Fraction a[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                swap(a[j], a[i]);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter n: ";  cin>>n;
    Fraction list[n];
    input(list,n);
    output(list, n);
    sort(list, n);
    cout<<"-->After sort:"<<endl;
    output(list, n);
}
