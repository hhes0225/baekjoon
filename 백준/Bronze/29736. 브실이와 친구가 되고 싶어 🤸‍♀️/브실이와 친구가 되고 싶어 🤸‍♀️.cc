#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int a, b, k, x;
    cin>>a>>b>>k>>x;

    int friends=0;

    for(int i=k-x;i<=k+x;i++){
        if(i>=a && i<=b){
            friends++;
        }
    }
    
     if(friends==0){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<friends<<"\n";
    }
    
    return 0;
}