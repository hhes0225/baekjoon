#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int, int> PII;

int n, e;
int from, to, weight;
int v1, v2;

vector<vector<PII>> adjList;
vector<int> shortestPath;
//i번째 노드에 도달하기 위한 최단거리

void djikstra(int start){
    fill(shortestPath.begin(), shortestPath.end(), INT_MAX);
    shortestPath[start]=0;
    
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        for(int i=0;i<adjList[curNode].size();i++){
            PII next = adjList[curNode][i];

            if(shortestPath[next.second]>shortestPath[curNode]+next.first){
                shortestPath[next.second]=shortestPath[curNode]+next.first;
                pq.push({next.first, next.second});
            }
        }
    }
    
}

int main() {
    cin>>n>>e;

    adjList.resize(n+1);
    shortestPath.assign(n+1, INT_MAX);

    for(int i=0;i<e;i++){
        cin>>from>>to>>weight;

        adjList[from].push_back({weight, to});
        adjList[to].push_back({weight, from});
    }

    //이 두 정점을반드시 거쳐야 함
    cin>>v1>>v2;

    /*
        두 정점을 반드시 거쳐야 함
        CASE1:
        1~v1까지의 최단거리 구하기
        v1~v2까지의 최단거리 구하기
        v2~n까지의 최단거리 구하기

        or

        CASE2:
        1~v2까지의 최단거리 구하기
        v2~v1까지의 최단거리 구하기
        v1~n까지의 최단거리 구하기
    */

    /*
        유효하지 않는 길 처리하기:
        경로가 중간에 한 번이라도 없으면 전체 경로가 끊어져서
        n 까지 도달할 수 없는 상태가 됨.
        따라서, 중간 경로에서 하나라도 최단 경로가 없으면
        해당 경로는 성립할 수 없으므로 전체 경로를
        ** 유효하지 않은 경로** 로 처리해야 함
    */

    //CASE1
    int case1=0;
    djikstra(1);
    if(shortestPath[v1]!=INT_MAX){
        case1+=shortestPath[v1];

        djikstra(v1);
        if(shortestPath[v2]!=INT_MAX){
            case1+=shortestPath[v2];
            djikstra(v2);
            if(shortestPath[n]!=INT_MAX)
                case1+=shortestPath[n];
            else{//v2 ~ n까지 가는 길이 없을 경우
                case1=-1;
            }
        }
            
        else{
        //v1 ~ v2까지 가는 길이 없을 경우
            case1=-1;
        }
        
        
    }
    else{//1 ~ v1까지 가는 길이 없을 경우
        case1=-1;
    }
        

    //cout<<case1<<endl;

    //CASE2
    int case2=0;
    djikstra(1);
    if(shortestPath[v2]!=INT_MAX){
        case2+=shortestPath[v2];

        djikstra(v2);
        if(shortestPath[v1]!=INT_MAX){
            case2+=shortestPath[v1];
            djikstra(v1);
            if(shortestPath[n]!=INT_MAX)
                case2+=shortestPath[n];
            else{//v2 ~ n까지 가는 길이 없을 경우
                case2=-1;
            }
        }
            
        else{
        //v1 ~ v2까지 가는 길이 없을 경우
            case2=-1;
        }
        
        
    }
    else{//1 ~ v1까지 가는 길이 없을 경우
        case1=-1;
    }

    //cout<<case2<<endl;

    if(min(case1, case2)<=0){//아예 가는 길이 없다면
        cout<<-1<<"\n";
        return 0;
    } 

    cout<<min(case1, case2)<<"\n";
    
    return 0;
}