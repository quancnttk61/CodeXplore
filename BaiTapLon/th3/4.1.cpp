// Nguyen Minh Quân 6151071087
#include <iostream>
#include <string>
using namespace std;

void input(string Num[], int &n)
{
    cout<<"Enter the number of strings: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the strings "<<i+1<<": "<<endl;
        getline(cin, Num[i]);
    }
}
string FindMax(string Num[], int n)
{
    string max = Num[0];
    for(int i=0; i<n; i++)
        if(Num[i] > max)
           max = Num[i];
    return max;
}
void display(string Num[], int n)
{
    string max = FindMax(Num, n);
    cout<<" max is: "<<max<<endl;
}
int main()
{
    int n;
    string Num[n];
    input(Num, n);
    display(Num, n);
}
