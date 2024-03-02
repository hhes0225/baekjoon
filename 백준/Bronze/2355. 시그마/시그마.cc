#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int a, b;
    long long int sum=0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b;

    if(a==b){
        sum=a;
    }
    else{
        sum=(a+b)*(abs(b-a)+1)/2;
    } 


    cout<<sum<<'\n';

    return 0;
}