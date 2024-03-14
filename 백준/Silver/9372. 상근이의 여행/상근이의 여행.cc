#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> adjList;

int country, plane;//node, edge
int total=0;


//dfs는 recursive 사용
void dfs(int node){
    visited[node]=true;
    //cout<<node<<endl;
    //cout<<"total++"<<endl;

    for(int i=0;i<adjList[node].size();i++){
        int next=adjList[node][i];

        if(visited[next]==false){
            total++;
            dfs(next);
        }
    }
}


int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        //cout<<"case#"<<i+1<<endl;
        cin>>country>>plane;
        
        adjList.resize(country+1);
        visited=vector<bool>(country+1, false);
        
        for(int j=0;j<plane;j++){
            int from, to;
            cin>>from>>to;
            
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        for(int j=1;j<adjList.size();j++){
            sort(adjList[j].begin(), adjList[j].end());
        }
        dfs(1);

        cout<<total<<"\n";
        
        adjList.clear();
        visited.clear();
        total=0;
    }

    return 0;
}