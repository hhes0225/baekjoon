#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

#define PII pair<int, int>

// (노드, 거리)
// 주어진 경로 중 특정 경로(g-h 경로)를 반드시 지나야 함


int n, m, t_destNum;
int src, g_dropBy, h_dropBy;
int from, to, weight;
vector<vector<PII>> adjList;
vector<int> distance_S;
vector<int> distance_G;
vector<int> distance_H;
vector<int> destinations;
int dist_GH;

void makeGraph() {
    cin >> n >> m >> t_destNum;
    cin >> src >> g_dropBy >> h_dropBy;

    adjList.assign(n + 1, vector<PII>());
    distance_S.assign(n + 1, INT_MAX);
    distance_G.assign(n + 1, INT_MAX);
    distance_H.assign(n + 1, INT_MAX);
    destinations.clear();

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    }

    for (int i = 0; i < t_destNum; i++) {
        int tmp;
        cin >> tmp;
        destinations.push_back(tmp);
    }
}

void dijkstra(int src, vector<int>& dists) {
    dists[src] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dists[curNode] < distance) {
            continue;
        }

        for (const auto& edge : adjList[curNode]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (nextDistance < dists[next]) {
                dists[next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
    }
}

int main() {
    int tCase;
    cin >> tCase;

    while (tCase--) {
        makeGraph();

        //S부터 각 노드까지 최단 거리
        dijkstra(src, distance_S);
        //G부터 각 노드까지 최단 거리
        dijkstra(g_dropBy, distance_G);
        //H부터 각 노드까지 최단 거리
        dijkstra(h_dropBy, distance_H);

        //G와 H 사이 거리
        dist_GH = distance_G[h_dropBy];
        
        sort(destinations.begin(), destinations.end());

        for (int dest : destinations) {
            //s->g->h->dest 혹은 s->h->g->dest 경로인지 확인
            //s~최종목적지 최단거리 
            // = s~g 최단거리 + g~h 거리+h~최종목적지 최단거리(s->g->h->dest)
            //s~최종목적지 최단거리
            // = s~h 최단거리 + g~h 거리+h~최종목적지 최단거리(s->g->h->dest)
            if (distance_S[dest] == distance_S[g_dropBy] + dist_GH + distance_H[dest] ||
                distance_S[dest] == distance_S[h_dropBy] + dist_GH + distance_G[dest]) {
                cout << dest << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
