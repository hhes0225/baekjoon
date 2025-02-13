#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> PDI;
const int SPEED =5;

struct Node {
    double x;
    double y;
};

vector<vector<PDI>> adjList;
vector <Node> nodes;
vector<double> visited;

double getDist(Node n1, Node n2){
    return sqrt(pow(n2.x-n1.x,2)+pow(n2.y-n1.y,2));
}

void dijkstra(int n){
    visited[n]=0;

    priority_queue<PDI, vector<PDI>, greater<>> pq;
    pq.push({0, n});

    while(!pq.empty()){
        auto [curDist, curNode]=pq.top();
        pq.pop();

        if(visited[curNode]<curDist) continue;

        //cout<<curDist<<" "<<curNode<<"\n";
        
        for(auto it:adjList[curNode]){
            auto [nextDist, nextNode]=it;

            if(visited[nextNode]>curDist+nextDist){
                visited[nextNode]=curDist+nextDist;
                pq.push({curDist+nextDist, nextNode});
                
            }
        }           
    }
    /*
    for(auto i:visited){
        cout<<i<<" | ";
    }
    cout<<"\n\n";
    */
}

int main() {
    Node src, dst;
    cin>>src.x>>src.y>>dst.x>>dst.y;

    int n;
    cin>>n;

    adjList.resize(n+2);
    nodes.resize(n+2);
    visited.assign(n+2, DBL_MAX);
    
    nodes[0]=src;//0번째 노드==시작점
    nodes[n+1]=dst;//n+1번째 노드==도착점
    
    for(int i=1;i<=n;i++){
        cin>>nodes[i].x>>nodes[i].y;
    }

    //비용==시간으로 그래프 만들기
    for(int i=0;i<n+1;i++){//n+1(도착점)에서는 이동하지 않으므로 제외
        for(int j=0;j<n+2;j++){
            if(i==j) continue;
            if(i==0||j==0) {//0(시작점)에서는 무조건 걸어야 함
                adjList[i].push_back({getDist(nodes[i], nodes[j])/SPEED, j});
            }
            else {//대포 노드의 경우 걷기 vs 대포 발사 시간 비교
                double cand1=getDist(nodes[i], nodes[j])/SPEED;//걷기
                double cand2=2+fabs(getDist(nodes[i], nodes[j])-50)/SPEED;//대포+남은 거리 걷기

                if(cand1>cand2){
                    adjList[i].push_back({cand2, j});
                }
                else{
                    adjList[i].push_back({cand1, j});
                }
            }
        }
    }

    /*
    for(auto i:adjList){
        for(auto j:i){
            cout<<j.first<<" "<<j.second<<" | ";
        }
        cout<<"\n\n";
    }
    */
    dijkstra(0);
    printf("%lf", visited[n+1]);


    return 0;
}