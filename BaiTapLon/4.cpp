//Nguyen Minh Quan- 6151071087
#include<iostream>
using namespace std;
class vector{
    private:
        int n;
        float *v;
    public:
        vector(int size);
        vector(vector &a);
        ~vector();
        void add();
        void display();
        bool check(vector &b);
        friend vector operator +(vector &a,vector &b);
        void operator =(vector &a);
};
vector::vector(int size){
    n = size;
    v = new float[n];
}
vector::vector(vector &a){
    n = a.n;
    v = new float [n];
    for (int i=0; i<n; i++)   v[i]=a.v[i];
}
vector::~vector(){
    delete v;
}
void vector::add(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}
bool vector::check(vector &b){
    return n==b.n;
}
vector operator +(vector &a,vector &b){
    vector c = a;
    for (int i=0; i<a.n; i++)
        c.v[i]=a.v[i]+b.v[i];
    return c;
}
void vector:: operator =(vector &a){
    n = a.n;
    v = new float[n];
    for (int i=0; i<n; i++)
    v[i]=a.v[i];
}
void vector::display(){
    for(int i=0; i<n; i++)    cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Nhap so luong phan tu cua vector A: "; cin>>n;
    vector a(n);
    a.add();
    a.display();
    cout<<"Nhap so luong phan tu cua vector B: "; cin>>n;
    vector b(n);
    b.add();
    b.display();
    cout<<"Tinh tong 2 vec to A và B: ";
    if(a.check(b)){
        (a+b).display();
    }else   cout<<"Ernor"<<endl;
