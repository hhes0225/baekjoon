#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> comb;
vector<bool> visited;

void backtracking(int limit, int n){
    if(limit==0){
        for(auto c:comb) cout<< c<<" ";
        cout<<"\n";

        return;
    }

    for(int i=n;i>0;i--){
        if(visited[i]) continue;

        visited[i]=true;
        comb.push_back(i);

        backtracking(limit-1, n);

        visited[i]=false;
        comb.pop_back();
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    visited.assign(n+1, false);
    backtracking(n, n);

    return 0;
}
