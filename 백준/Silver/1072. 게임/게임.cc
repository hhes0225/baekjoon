#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, y;
    cin>>x>>y;

    ll z=y*100/x;

    if(z>=99){
        cout<<-1<<"\n";
        return 0;
    }

    ll left=1, right=INT_MAX;
    ll newX=-1, newY=-1;

    while(left<=right){
        ll mid=(left+right)/2;

        newX=x+mid;
        newY=y+mid;
        
        ll newZ=newY*100/newX;
            
        if(z<newZ){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    if(y==newY) cout<<-1<<"\n";
    else    cout<<left<<"\n";

    
    
    return 0;
}