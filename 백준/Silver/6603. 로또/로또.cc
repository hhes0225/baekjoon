#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<bool> visited;
vector<int> combination;

void backtracking(int n, int size, int limit){
    if(limit==6){
        for(auto c:combination) cout<<c<<" ";
        cout<<"\n";
    }

    for(int i=n;i<size;i++){
        if(!visited[i]){
            visited[i]=true;
            combination.push_back(nums[i]);

            backtracking(i+1, size, limit+1);

            //원복
            visited[i]=false;
            combination.pop_back();
        }
    }
}

int main() {
    while(1){
        int s;
        cin>>s;

        if(s==0) break;

        nums.resize(s);
        visited.assign(s, false);
        for(auto &n:nums) cin>>n;

        backtracking(0, s, 0);

        cout<<"\n";
    }
    return 0;
}