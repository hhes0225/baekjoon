#include <bits/stdc++.h>
using namespace std;

/*
    일단 n=1, m=10^18일 때,
    귤은 10^18-1 일에 귤 1개만 남으므로
    10^100까지 갈 필요 없이 최대 일수는 10^18-1

    
*/

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll m;
    cin>>n>>m;

    vector<ll> gomgom;
    gomgom.resize(n);
    for(int i=0;i<n;i++){
        cin>>gomgom[i];
    }

    vector<ll> P(n+1, 0);
    for(int i = 1; i <= n; i++){
        P[i] = P[i-1] + gomgom[i-1];
    }
    ll S = P[n];

    while (true) {
        ll sum=0;
        for(int i=0;i<n;i++){
            if(m<sum+gomgom[i]) continue;
            sum+=gomgom[i];
        }

        if(sum==0) break;

        m%=sum;
    }

    cout<<m;

    
    
    return 0;
}