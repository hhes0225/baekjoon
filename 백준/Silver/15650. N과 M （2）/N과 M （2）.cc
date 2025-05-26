#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> combination;
int ans=0;

void backtracking(int lastNum, int limit, int m){
    if(m==0){
        ans++; 
        
        for(auto c:combination) cout<< c<<" ";
        cout<<"\n";
        
        return;
    }

    for(int i=lastNum;i<=limit;i++){
        if(!visited[i]){
            visited[i]=true;
            combination.emplace_back(i);
            
            backtracking(i+1, limit, m-1);

            //데이터 원복
            visited[i]=false;
            combination.pop_back();
        }
    }
}

int main() {
    //1~n 자연수 중 중복 없이!! M개 고른 수열
    int n, m;
    cin>>n>>m;

    visited.assign(n, false);
    
    backtracking(1, n, m);
        
    return 0;
}