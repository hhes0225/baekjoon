#include <iostream>
#include <vector>
using namespace std;

//그래프의 인접 리스트 만드는 느낌으로 해결
int node, edge;
vector<vector<int>> adjList;


int main() {
    cin>>node>>edge;

    adjList.resize(node+1);

    for(int i=0;i<edge;i++){
        int from, to;
        cin>>from>>to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    for(int i=1;i<adjList.size();i++){
        cout<<adjList[i].size()<<"\n";
    }
    
    
    return 0;
}