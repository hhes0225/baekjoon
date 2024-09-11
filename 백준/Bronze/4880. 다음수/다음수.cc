#include <iostream>
using namespace std;

int main() {
    int a,b,c;

    while(1){
        cin>>a>>b>>c;

        if(a==0&&b==0&&c==0){
            break;
        }

        int gap1=b-a;
        int gap2=c-b;
        if(gap1==gap2){
            cout<<"AP ";
            cout<<c+gap1<<"\n";
        }
        else{
            gap1=b/a;
            gap2=c/b;
            cout<<"GP ";
            cout<<c*gap1<<"\n";
        }
    }
    return 0;
}