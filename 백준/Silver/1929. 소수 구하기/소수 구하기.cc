#include <iostream>
#include <vector>

using namespace std;

vector<bool> prime;

void checkPrime(int n){
    prime[0]=false, prime[1]=false;
    
    for(int i=2;i<n+1;i++){
        if(prime[i]==false){
            continue;            
        }
        
        for(int j=i*2;j<n+1;j+=i){
            //if(prime[j]==true)
            prime[j]=false;            
        }
    }
    
    
}

int main(void){
    int from, to;
    cin>>from>>to;

    //초기화할때: (초기화할 크기, 초기화할 값)으로 설정
    prime=vector<bool>(to+1, true);

    checkPrime(to);

    for(int i=from;i<=to;i++){
        if(prime[i]==true)
            cout<<i<<"\n";
    }

    return 0;
}