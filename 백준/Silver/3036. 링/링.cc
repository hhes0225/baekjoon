#include <iostream>
#include <vector>
using namespace std;

void gcd(int a, int b){
    int maxgcd;
    
    for(int i=1;i<=max(a,b);i++){
        if(a%i==0 && b%i==0){
            maxgcd=i;
        }
    }
    
    cout<<a/maxgcd<<"/"<<b/maxgcd<<endl;
    
}

int main(void){
    int tCase;
    int firstRing;
    vector<int> rings;
    
    cin>>tCase;
    
    cin>>firstRing;
    rings.resize(tCase-1);
    
    for(int i=0;i<rings.size();i++){
        cin>>rings[i];
    }
    
    //만약 나누어떨어지면 끝
    //안 나누어떨어지면 최대공약수로 나누기
    for(int i=0;i<rings.size();i++){
        if(firstRing%rings[i]==0 || rings[i]%firstRing==0){
            cout<<firstRing/min(firstRing, rings[i])<<"/"<<rings[i]/min(firstRing, rings[i])<<endl;
        }
        else{
            gcd(firstRing, rings[i]);
        }
    }
    
    return 0;
}