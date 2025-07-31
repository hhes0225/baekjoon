#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;

vector<PLL> cave;
set<ll> clear;
vector<bool> visited;
vector<vector<PLL>> tips;

int main() {
    ll n, m;
    cin>>n>>m;

    cave.resize(n);
    visited.assign(n+1, false);
    tips.resize(n+1);

    for(ll i=0;i<n;i++){
        ll lv;cin>>lv;
        cave[i]={lv, i+1};
    }


    int tNum; cin>>tNum;
    for(int i=0;i<tNum;i++){
        int a,b,t;
        cin>>a>>b>>t;
        tips[a].push_back({b,t});
        cave[b-1].first+=t;
    }

    //-----------------------

    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    ll clearLv=0;

    for(int i=0;i<cave.size();i++){
        pq.push(cave[i]);
    }

    // while(!pq.empty()){
    //     auto [lv, idx]=pq.top();
    //     cout<<lv<<" "<<idx<<"\n";
    //     pq.pop();
    // }

    while(m>0 && !pq.empty()){
        auto [lv, idx]=pq.top();
        pq.pop();

        bool canDecrease=false;
        
        if(visited[idx]) continue;
        visited[idx]=true;

        //만약 팁 있으면 팁 적용
        for(auto tip: tips[idx]){
            if(visited[tip.first]) continue;
            cave[tip.first-1].first-=tip.second;
            pq.push({cave[tip.first-1].first, tip.first});
        }

        clearLv=max(clearLv, lv);
        m--;
    }

    cout<<clearLv<<"\n";
    
    
    
    return 0;
}