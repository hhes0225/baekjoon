#include <bits/stdc++.h>
using namespace std;

vector<int> kits;
int cases=0;
int n, k;
vector<bool> visited;
vector<int> order;

void backtracking(int w, int day){
    if(w<500) return;
    if(day==n){
        cases++;
        // for(auto o:order) cout<<o<<" ";
        // cout<<"\n";
        return;
    }
    

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            // order.push_back(i);

            
            backtracking(w-k+kits[i], day+1);

            //원복
            visited[i]=false;
            // order.pop_back();
        } 
        
    }
}

int main() {
    cin>>n>>k;

    kits.resize(n);
    visited.assign(n, false);
    for(auto &k:kits) cin>>k;
    
    backtracking(500, 0);

    cout<<cases;
    
    return 0;
}