#include <bits/stdc++.h>
using namespace std;

vector<int> comb;
vector<bool> visited;

void backtracking(int prev, int n, int m){
    if(m==0){
        for(auto c:comb){
            cout<<c<<" ";
        }
        cout<<"\n";

        return;
    }

    for(int i=prev;i<=n;i++){
        comb.push_back(i);

        backtracking(i, n, m-1);

        comb.pop_back();
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    backtracking(1, n, m);
    
    
    return 0;
}