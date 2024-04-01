#include <iostream>
#include <vector>
using namespace std;

//vector<vector<pair<int, int>>> isPrime;
vector<bool> isPrime;

void prime(int n){
    isPrime[0]=false, isPrime[1]=false;
    
    for(int i=2;i<25;i++){
        if(isPrime[i]){
            for(int j=i*2;j<n;j+=i){
                //isPrime[j].push_back({i, k});
                isPrime[j]=false;
            }
        }
    }
    
}

int main(void){
    int tCase;
    cin >> tCase;

    //isPrime.resize(100000+1);
    isPrime=vector<bool>(100000+1, true);
    
    prime(100000+1);

    
    
    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;
        int tmp=input;
        
        vector<int> division;
        division=vector<int>(input+1, 0);

       
        for(int j=2;tmp>1;j++){
            if(isPrime[j]){
                 while(tmp%j==0){
                     division[j]++;
                     tmp/=j;
                }
            }
        }

        for(int j=2;j<input+1;j++){
            if(division[j]!=0){
                cout<<j<<" " <<division[j]<<"\n";
            }
        }
    }
    
    return 0;
}