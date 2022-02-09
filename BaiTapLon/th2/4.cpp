class MyAddress {
    protected:
        string address;
    public:
        MyAddress();
        ~MyAddress();
        void PrintAddress();
};
MyAddress::MyAddress(){
    address = "";
}
MyAddress::~MyAddress(){}
void MyAddress::PrintAddress(){
    cout << "Address: " << address ;
}
class Person : public MyAddress{
    protected:
        string name;
        int Phone;
    public:
        Person();
        ~Person();
};
Person::Person(){
    name = "";
    address = "";
    Phone = 0;
}
Person::~Person(){}

class Officer : public Person{
    private:
        float Salary;
    public:
        Officer();
        void Input();
        void Print();
        bool operator > (Officer &a);
        void sort();
};
Officer::Officer(){
    name = "";
    address = "";
    Phone = 0;
    Salary = 0;
}
void Officer::Input(){
    fflush(stdin);
    cout << "Enter name: ";
    getline(cin,name);
    cout << "Enter Address: ";
    getline(cin,address);
    cout << "Enter Phone: ";
    cin >> Phone;
    cout << "Enter Salary: ";
    cin >> Salary;
}
void Officer::Print(){
    cout << "name: "<<name<<" Address: "<< address <<" Phone: "<< Phone<<" Salary: "<< Salary<<endl;
}
bool Officer::operator > (Officer &a){
    if (Salary > a.Salary)
        return true;
}
void Officer::sort(){
    Officer *a;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i) > (a+j)){
                swap(*(a+i),*(a+j));
            }
        }
    }
    Print();
}
int main (){
    Officer *a= new Officer[4];
    for(int i = 0; i < 4; i++){
        cout << endl<< "Information "<< i+1 << endl;
        (a+i)->Input();
    }
    for(int i = 0; i < 4; i++){
        cout << endl<< "Information "<< i+1 << endl;
        (a+i)->Print();
    }
    a->sort();
    return 0;
}
