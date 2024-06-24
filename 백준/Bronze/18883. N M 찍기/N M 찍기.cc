#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    int x=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==m){
                cout<<x;
            }
            else{
                cout<<x<<" ";
            }
            x++;
        }
        cout<<endl;
        
    }
    
    return 0;
}