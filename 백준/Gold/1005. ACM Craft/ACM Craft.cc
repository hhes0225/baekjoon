#include <bits/stdc++.h>
using namespace std;

vector<int> minBuildTimeDP;
vector<int> duration;
vector<vector<int>> adjList;

int GetMinBuildTime(int node){

    if(minBuildTimeDP[node]!=-1){
        return minBuildTimeDP[node];
    }
    
    if(adjList[node].size()==0){
        return duration[node];
    }

    
    for(int i=0;i<adjList[node].size();i++){
        minBuildTimeDP[node]=max(minBuildTimeDP[node], GetMinBuildTime(adjList[node][i]));
    }

    minBuildTimeDP[node]+=duration[node];

    return minBuildTimeDP[node];
}

int main() {
    int tCase;
    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int n, k;
        cin>>n>>k;

        adjList.clear();
        adjList.resize(n+1);
        minBuildTimeDP.assign(n+1, -1);
        duration.assign(n+1, 0);

        for(int j=1;j<=n;j++){
            cin>>duration[j];
        }
        
        for(int j=0;j<k;j++){
            int from, to;
            cin>>from>>to;

            adjList[to].push_back(from);
        }

        int src;
        cin>>src;

        cout<< GetMinBuildTime(src)<<"\n";
    }

    
    return 0;
}