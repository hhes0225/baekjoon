#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> positiveDP;
vector<int> negativeDP;

int tabulation(int n){
    if(n==0||n==1){
        return n;
    }

    positiveDP[0]=0, positiveDP[1]=1;
    negativeDP[0]=0, negativeDP[1]=1;

    //양수면
    if(n>0){
        for(int i=2;i<n+1;i++){
            positiveDP[i]=(positiveDP[i-1]+positiveDP[i-2])%1000000000;   
        }

        return positiveDP[n];
        
    }
    //음수면
    else{
        for(int i=2;i<abs(n)+1;i++){
            negativeDP[i]=(negativeDP[i-2]-negativeDP[i-1])%1000000000;
        }
        return negativeDP[abs(n)];
    }
    
}

int main(void){
    int input;
    cin>>input;

    positiveDP.resize(1000000+1);
    negativeDP.resize(1000000+1);

    int result=tabulation(input);

    if(result<0){
        cout<<"-1\n";
    }
    else if(result==0){
        cout<<"0\n";
    }
    else{
        cout<<"1\n";
    }

    cout<<abs(result)<<"\n";

    return 0;
}