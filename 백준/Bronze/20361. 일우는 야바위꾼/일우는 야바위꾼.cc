#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n,x,k;
    cin>>n>>x>>k;

    vector<int> cups;
    cups.resize(n+1);

    cups[x]=1;

    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;

        if(cups[a]==1){
            cups[a]=0;
            cups[b]=1;
        }
        else if(cups[b]==1){
            cups[a]=1;
            cups[b]=0;
        }
        else{
            continue;
        }
    }

    for(int i=1;i<cups.size();i++){
        if(cups[i]==1){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}