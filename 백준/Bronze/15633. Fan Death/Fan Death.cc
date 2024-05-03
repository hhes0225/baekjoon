#include<iostream>
#include <vector>
using namespace std;

int main(void){
    int input;
    cin>>input;
    int sum=0;

    for(int i=1;i<=input;i++){
        if(input%i==0){
            sum+=i;
        }
    }

    cout<<sum*5-24<<endl;
    
    
    return 0;
}