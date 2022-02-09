//Nguyen Minh Quan 6151071087
#include<iostream>
using namespace std;

class vector{
    private:
        int n;
        float *v;
    public:
        vector(int size);
        vector(vector &vt);
        ~vector();
        void Nhap();
        void Xuat();
        int Check(vector &p);
        friend vector operator +(vector &a,vector &b);
        void operator =(vector &);
};
vector::vector(int size)
{
    n = size;
    v = new float [n];
}

vector::vector(vector &vt)
{
    n = p.n;
    v = new float [n];
    for (int i = 0; i < n; i++)
    v[i] = p.v[i];
}
vector::~vector()
{
    delete v;
}
void vector::Nhap()
{
    for (int i = 0; i < n; i++)
    {
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}

void vector::Xuat()
{
    for (int i = 0; i < n; i++)
    cout<<v[i]<<"       ";
}

int vector::Check(vector &vt)
{
    if (n == p.n) 
        return 1;
    return 0;
}
vector operator +(vector &a,vector &b)
{
    vector c = b;
    for (int i = 0;i < b.n; i++)
    c.v[i] = a.v[i] + b.v[i];
    return c;
}

void vector:: operator =(vector &p)
{
    n = p.n;
    v = new float [n];
    for (int i = 0; i < n; i++)
    v[i] = p.v[i];
}

int main()
{
    int n;
    vector a(n), b(n);
    cout<<"Nhap so phan tu cua vector A: ";cin>>n;
    a.Nhap();
    cout<<"\nNhap so phan tu cua vector B: ";cin>>n;
    b.Nhap();
    cout<<"vector a: ";
	a.Xuat();
    cout<<endl<<"vector b: ";b.Xuat();
    if(a.Check(b)==1) 
    {
        cout<<"Tong 2 vector A va B: ";
        (a+b).Xuat();
    }
    else 
        cout<<"erorr ";
    return 0;
}
