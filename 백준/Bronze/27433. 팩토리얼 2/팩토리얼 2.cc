#include <iostream>

using namespace std;

int main(void){
    int num;
    long long int facto=1;
    
    cin>>num;
    
    if(num==0 || num==1){
        facto=1;
    }
    else{
        for(int i=1;i<=num;i++){
            facto*=i;
        }
    }
    
    cout<<facto<<endl;
    
    return 0;
}