#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

#define PII pair<int, int>

// (노드, 거리)

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

        dijkstra(src, distance_S);
        dijkstra(g_dropBy, distance_G);
        dist_GH = distance_G[h_dropBy];
        dijkstra(h_dropBy, distance_H);
        sort(destinations.begin(), destinations.end());

        for (int dest : destinations) {
            if (distance_S[dest] == distance_S[g_dropBy] + dist_GH + distance_H[dest] ||
                distance_S[dest] == distance_S[h_dropBy] + dist_GH + distance_G[dest]) {
                cout << dest << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
