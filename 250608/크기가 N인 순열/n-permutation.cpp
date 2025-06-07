#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> combination;
vector<bool> visited;

void backtracking(int limit, int n){
    if(limit==0){
        for(auto c:combination) cout<< c<<" ";
        cout<<"\n";

        return;
    }

    for(int i=1;i<=n;i++){
        if(visited[i]) continue;

        visited[i]=true;
        combination.push_back(i);

        backtracking(limit-1, n);

        visited[i]=false;
        combination.pop_back();
    }
}

int main() {
    cin >> n;

    visited.assign(n+1, false);

    // Please write your code here.
    backtracking(n, n);

    return 0;
}
