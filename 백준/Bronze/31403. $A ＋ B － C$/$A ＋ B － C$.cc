#include <iostream>
#include <string>
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;

    int integer=a+b-c;
    string tmp=to_string(a);
    tmp+=to_string(b);

    int str = stoi(tmp)-c;

    cout<<integer<<"\n"<<str<<"\n";
    
    return 0;
}