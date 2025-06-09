#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> comb;
vector<bool> visited;
set<vector<int>> ans;
int n, m;

void backtracking(int from, int limit){
    if(limit==0){
        // for(auto c:comb){
        //     cout<<c<<" ";
        // }
        // cout<<"\n";

        ans.insert(comb);

        return;
    }

    for(int i=1;i<=n;i++){
        // if(visited[i]) continue;

        // visited[i]=true;
        comb.push_back(i);

        backtracking(i, limit-1);

        // visited[i]=false;
        comb.pop_back();
        
    }

    
}



int main() {
    cin>>n>>m;

    backtracking(1, m);

    for(auto a:ans){
        for(auto j:a){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}