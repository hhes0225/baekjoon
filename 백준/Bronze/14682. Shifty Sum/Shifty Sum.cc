#include <iostream>
using namespace std;
int main() {
    int num, shift;
    int result=0;

    cin>>num>>shift;
    
    for(int i=0;i<shift+1;i++){
        result+=num;
        num*=10;
    }

    cout<<result<<"\n";
    
    return 0;
}