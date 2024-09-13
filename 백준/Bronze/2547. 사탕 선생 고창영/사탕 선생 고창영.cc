#include <iostream>
using namespace std;

int main() {
    long long int tCase;
    long long int students;
    long long int sum=0;

    cin>>tCase;
    
    for(int i=0;i<tCase;i++){
        cin>>students;
        long long int tmp;

        for(int j=0;j<students;j++){
            cin>>tmp;
            sum+=(tmp%students);
        }

        //cout<<sum<<endl;

        if(sum%students==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

        sum=0;
    }
    
    return 0;
}