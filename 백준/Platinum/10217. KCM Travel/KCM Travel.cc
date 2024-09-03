#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

/*
    문제 1: pq 정렬

    문제 2: vector<Cost> totalCost 
    -> vector<vector<int>> totalCost(totalcost[node][price]:node에 price로 도달했을 때 최소시간)

    문제 3: adjList 정렬
    
    <adjList에서 duration에 따라 정렬해주어야 하는 이유>
    우선순위 큐의 효율성:
    정렬된 간선 리스트를 사용하면, 우선순위 큐에 삽입되는 간선들이 이미 정렬된 상태이므로, 큐의 삽입 및 삭제 연산이 더 효율적으로 수행됩니다.
    이는 큐의 내부 정렬 작업을 줄여주어, 전체 알고리즘의 실행 시간을 단축시킵니다.
    탐색의 효율성:
    정렬된 간선 리스트를 사용하면, 탐색 과정에서 불필요한 간선을 탐색하지 않게 됩니다.
    이는 탐색 과정에서의 비교 연산을 줄여주어, 전체 알고리즘의 실행 시간을 단축시킵니다.
*/

class Cost{
public:
    int price;
    int duration;

    Cost():price(0), duration(INT_MAX){};
    Cost(int price, int duration):price(price), duration(duration){}
};

int airports;
int budget;
int tickets;

vector<vector<pair<int, Cost>>> adjList;
vector<vector<int>> totalCost;
//totalCost[node][budget] : 각 노드에서 비용에 따른 최소 시간 기록
//node 번에서 budget 돈을 가지고 있는 상태에서 가지는 최소 시간

typedef pair<int, pair<int, int>> PIPII;


void djikstra(int start){
    totalCost[start][budget]=0;
    
    priority_queue<PIPII, vector<PIPII>, greater<PIPII>> pq;
    pq.push({0, {start, budget}});

    while(!pq.empty()){
        auto curNodeInfo = pq.top();
        int curTime=curNodeInfo.first;
        int cur = curNodeInfo.second.first;
        int curBudget = curNodeInfo.second.second;
        
        pq.pop();

        if(curTime>totalCost[cur][curBudget]) continue;


        for(size_t i=0;i<adjList[cur].size();i++){
            auto nextNode = adjList[cur][i].first;
            auto nextCost = adjList[cur][i].second;

            if(curTime+nextCost.duration<totalCost[nextNode][curBudget-nextCost.price]){
                if(curBudget-nextCost.price>=0){
                    //방문처리
                    totalCost[nextNode][curBudget-nextCost.price]=curTime+nextCost.duration;
                    
                    //큐에 다음 노드 푸시하기
                    pq.push({curTime+nextCost.duration, {nextNode,curBudget-nextCost.price}});
                }
                
            }
            
        }
    }
    
    
}

int main() {
    int tCase;
    cin>>tCase;

    cin>>airports>>budget>>tickets;

    adjList.resize(airports+1);
    totalCost.resize(airports+1, vector<int>(budget+1, INT_MAX));
    
    for(int i=0;i<tickets;i++){
        int from, to, pr, du;
        cin>>from>>to>>pr>>du;

        adjList[from].push_back({to, Cost(pr, du)});
    }

    // 간선 리스트 정렬
    for (size_t i = 1; i <= airports; i++) {
    sort(adjList[i].begin(), adjList[i].end(), [](const pair<int, Cost>& a, const pair<int, Cost>& b) {
        return a.second.duration < b.second.duration;
    });
}


    djikstra(1);//시작 노드는 무조건 첫 번째 노드, ICN

    
    int result = INT_MAX;
    for (int i = 0; i <= budget; i++) {
        result = min(result, totalCost[airports][i]);
    }

    /* 각 공항까지 도달하기 위해 필요한 최소기간, 이때 소모되는 비용
    for(auto it:totalCost){
        cout<<it.price<<","<<it.duration<<"\n";
    }
    cout<<"\n";
    */

    if(result==INT_MAX){
        cout<<"Poor KCM\n";
    }
    else{
        //cout<<"LA(비용, 시간): "<<totalCost[totalCost.size()-1].price<<" "<<totalCost[totalCost.size()-1].duration<<endl;
        cout<<result<<endl;
    }
    
    return 0;
}
