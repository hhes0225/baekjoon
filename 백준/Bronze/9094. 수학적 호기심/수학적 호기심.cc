#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int n, m;
        int curiosity=0;
        
        cin>>n>>m;

        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((int)(pow(j,2)+pow(k,2)+m)%(j*k)==0){
                    curiosity++;
                }
            }
        }

        cout<<curiosity<<"\n";
    }
    
    return 0;
}