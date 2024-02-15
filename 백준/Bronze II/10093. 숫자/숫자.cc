#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    long long int n, m;
    
    cin>>n>>m;
    
    

    if(n==m){
        cout<<"0\n";
    }
    else{
        long long int bigger=max(n, m);
        long long int smaller=min(n, m);

        long long int gap=bigger-smaller-1;
    
        cout<<gap<<"\n";
        
        for(long long int i=smaller+1;i<bigger;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}