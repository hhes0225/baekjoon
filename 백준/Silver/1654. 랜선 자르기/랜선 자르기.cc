#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> lines;

bool canMakeNLines(ll len, ll n){
     ll nLines=0;

    for(ll l:lines){
        nLines+=(l/len);
    }

    return (nLines>=(ll)n);
}

int main() {
    int k, n;
    cin>>k>>n;

    lines.resize(k);
    for(auto &l:lines) cin>>l;

    sort(lines.begin(), lines.end());

    //최소 랜선 길이, 최대 랜선 길이
    ll left=1, right=lines.back();

    while(left<=right){
        ll mid=(left+right)/2;

        if(canMakeNLines(mid, n)){
            left=mid+1;//최대화
        }
        else{
            right=mid-1;
        }
    }

    cout<<right<<"\n";
    
    
    return 0;
}