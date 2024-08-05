#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;
#define PII pair<int, int>

enum wolfState{
    SLOWWALK=0,
    RUN=1 
};

class Wolf{
public:
    int nodeNum;
    int cost;
    int runOrWalk;
    Wolf(int n, int c, int r) : nodeNum(n), cost(c), runOrWalk(r) {}
};

struct compare{
    bool operator()(Wolf a, Wolf b){
        return a.cost>b.cost;
    }
};


int node, edge;
int from, to, weight;
vector<vector<PII>> graph;
vector<int> moonFox;
vector<vector<int>> moonWolf;

void makeGraph(){
    cin>>node>>edge;

    graph.resize(node+1);
    moonFox.assign(node+1, INT_MAX);
    moonWolf.resize(2);
    moonWolf[0].assign(node+1, INT_MAX); // SLOW WALK
    moonWolf[1].assign(node+1, INT_MAX); // RUN

    for(int i=0;i<edge;i++){
        cin>>from>>to>>weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
}

//여우 == 일반 다익스트라
void foxDijkstra(int src, vector<int>& foxDistance){
    foxDistance[src]=0;//첫 노드는 비용 0
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    //PII 타입 요소를 가지는 priority_queue를 vector로 구현, 최소 heap으로 동작하도록
    //최소 힙 == 부모 노드값이 자식 노드 값보다 항상 작음

    pq.push({0, src});//시작 노드부터 탐색 시작
    //pq는 비용 작은 순으로 정렬되어 있음.(first 기준, 서브기준 second)

    while(!pq.empty()){//pq가 빌 때까지
        int curNode = pq.top().second;//가장 비용 작은 노드의 노드값
        int distance = pq.top().first;
        // 시작 노드부터 curNode까지 거리(비용값)
        pq.pop();//이 노드에서 다른 노드까지 최소 거리 구할 것이므로 큐에서 뺀다.

        if(foxDistance[curNode]<distance){
            //curNode에 대해 이미 계산된 최단거리가 여전히 최단이라면
            continue;//curNode의 최단거리 계산 중단
            //만약 아래 for문에서 같은 노드에 대해 2개가 들어오면 최소가 아닌 것은
            //노드 최소경로 구하는 것이 아니라 아무 동작 없이 pop해야함
        }

        //최단거리라면 curNode에 연결된 모든 노드 순회하며 최단 거리 갱신
        for(const auto& edge : graph[curNode]){
            int next = edge.first;
            int nextDistance = distance+edge.second*2;

            //기존 계산한 src~nextNode 경로보다 최소라면 갱신
            if(nextDistance<foxDistance[next]){
                foxDistance[next]=nextDistance;
                pq.push({nextDistance, next});
            }
        }
        
    }
    
}

void wolfDijkstra(int src, vector<vector<int>>& wolfDistance){
    wolfDistance[0][src]=0;
    enum wolfState wState = RUN;
    priority_queue<Wolf, vector<Wolf>, compare> pq;
    
    Wolf tmp(src, 0, 0);
    pq.push(tmp);

    while(!pq.empty()){
        int curNode = pq.top().nodeNum;
        int distance = pq.top().cost;
        int turn = pq.top().runOrWalk;
        pq.pop();

        if(wolfDistance[turn%2][curNode]<distance){
            continue;
        }

        for(const auto&edge:graph[curNode]){
            int nextNode = edge.first;
            int nextDistance=edge.second;
            int next_turn = turn +1;

            //거리 = 속도*시간
            if(turn%2==0){
                nextDistance = distance+nextDistance;
                if(wolfDistance[1][nextNode]>nextDistance){
                    wolfDistance[1][nextNode]=nextDistance;
                    pq.push(Wolf(nextNode, nextDistance, next_turn));
                }
            }
            else{
                nextDistance = distance+nextDistance*4;
                if(wolfDistance[0][nextNode]>nextDistance){
                    wolfDistance[0][nextNode]=nextDistance;
                    pq.push(Wolf(nextNode, nextDistance, next_turn));
                }
            }
           
        }
    }
    
}

int main() {
    makeGraph();

    foxDijkstra(1, moonFox);
    wolfDijkstra(1, moonWolf);

    int answer=0;

    for(int i=2;i<=node;i++){
        if(moonFox[i]<min(moonWolf[0][i], moonWolf[1][i])){
            answer++;
        }
    }

    cout<<answer<<"\n";
    
    return 0;
}