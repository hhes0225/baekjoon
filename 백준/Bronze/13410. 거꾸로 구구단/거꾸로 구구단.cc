#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int a, b;
    cin>>a>>b;
    int maxResult=0;

    for(int i=1;i<=b;i++){
        int mul=a*i;
        string reverseMul=to_string(mul);
        reverse(reverseMul.begin(), reverseMul.end());
        mul=stoi(reverseMul);

        maxResult=max(maxResult, mul);
    }

    cout<<maxResult<<endl;
    
    return 0;
}