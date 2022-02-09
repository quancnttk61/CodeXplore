#include<bits/stdc++.h>
using namespace std;
template<class T>
class Swap{// viet 1 class, dung cho nhieu kieu
    public:
        T first,second;
        Swap(T first,T second){this->first = first;this->second =  second;}
        void swap(){
            T temp = first;
            first = second;
            second = temp;
        }
        string toString(){
            ostringstream ss;
            ss<<first<<" "<<second<<endl;
            return ss.str();
        }
};
int main(){
    Swap<int> number(3,4);
    number.swap();
    cout<<number.toString()<<endl;
    return 0;
}

