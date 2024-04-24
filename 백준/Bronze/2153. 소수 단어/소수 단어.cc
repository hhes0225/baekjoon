#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    string input;
    cin>>input;
    int sum=0;


    for(int i=0;i<input.size();i++){
        if((int)input[i]>=(int)'A'&&(int)input[i]<=(int)'Z'){
            sum+=(int)input[i]-(int)'A'+27;
        }
        else{
            sum+=(int)input[i]-(int)'a'+1;
        }
    }

    //cout<<sum<<endl;

    bool isPrime = true;
    for(int i=2;i<sum;i++){
        if(sum%i==0){
            isPrime=false;
        }
    }

    if(isPrime){
        cout<< "It is a prime word.\n";
    }
    else{
        cout<< "It is not a prime word.\n";
    }

    

    return 0;
}