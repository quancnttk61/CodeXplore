//Nguyen Minh Quan 6151071087
#include <iostream>
using namespace std;
class Student{
    private:
        string name;
        float mark_hk1,mark2;
        float average;
    public:
        Student ();
        void input ();
        void output();
        bool operator > (Student a);
};
Student::Student (){
    name = "";
    mark_hk1 = 0;
    mark2 = 0;
    average = 0;
}
void Student::input (){
    fflush(stdin);
    cout <<"Enter name: ";
    getline(cin,name);
    cout <<"Nhap diemtb hk1 ";
    cin >> mark_hk1;
    cout <<"Nhap Diemtb hk2 2: ";
    cin >> mark2;
    average = (mark_hk1+mark2*2)/3;
}
void Student::output(){
    cout <<"Name: "<<name<<"  Diem 1: "<<mark_hk1<<"  Diemtb hk 2: "<<mark_hk2<<"  Diemtb ca nam hoc: "<<Diemtb<<endl;
}
bool Student:: operator > (Student a){
    return Diemtb>a.Diemtb;
}
void input(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Nhap thong tin sinh vien" << i+1 << endl ;
        a[i].input() ;
    } 
}
void output(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"sinh vien" << i+1 << ": " ;
        a[i].output();
    }
}
void compare (Student a,Student b){
    if (a > b){
        cout <<"Diemtb sinh vien thu nhat lon nhat Diemtb thu hai"<<endl;
    }else {
        cout <<"Diemtb sinh vien thu nhat nho hon hoac bang Diemtb  sinh vien thu 2"<<endl;
    }
}
void sort(Student a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[j] > a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main (){
    Student sv1;
    Student sv2;
    cout <<"Student 1: "<<endl;
    sv1.input(); 
    cout <<"Student 2: "<<endl;
    sv2.input();
    sv1.output();
    sv2.output();
    compare (sv1, sv2);
    Student s[20];
    input(s,20;
    output(s,20);
    cout <<endl<<"sau khi sap xep"<<endl;
    sort(s,20);
    output(s,20);
    return 0;
}
