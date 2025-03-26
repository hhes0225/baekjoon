#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> combination;

void backtracking(int prev, int num){
    if(num==M){
        for(auto c:combination){
            cout<<c<<" ";
        }
        cout<<"\n";

        return;
    }

    for(int i=prev+1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            combination.push_back(i);

            backtracking(i, num+1);

            //원복
            visited[i]=false;
            combination.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    visited.assign(N+1, false);

    // Please write your code here.
    backtracking(0, 0);

    return 0;
}
