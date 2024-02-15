#include <iostream>

using namespace std;

int main(void){
    int n, m;
    
    cin>>n>>m;
    
    

    if(n==m){
        cout<<"0\n";
    }
    else{
        int bigger=max(n, m);
        int smaller=min(n, m);

        int gap=bigger-smaller-1;
    
        cout<<gap<<"\n";
        
        for(int i=smaller+1;i<bigger;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}