#include <bits/stdc++.h>
using namespace std;
const int MAX=123'456;

vector<bool> numIsPrime;

void erathos(){
    numIsPrime.assign(MAX*2+1, true);

    numIsPrime[0]=numIsPrime[1]=false;
    
    for(int i=2;i<=MAX;i++){
        for(int j=i+i;j<MAX*2+1;j+=i){
            numIsPrime[j]=false;
        }    
    }
}

int main() {
    erathos();
    
    while(1){
        int input;
        cin>>input;

        if(input==0) break;

        int ans=0;

        for(int i=input+1;i<=2*input;i++){
            if(numIsPrime[i]) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}