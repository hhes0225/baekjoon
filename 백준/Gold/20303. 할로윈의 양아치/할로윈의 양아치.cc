#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int child, rel, minCry;
vector<vector<int>> adjList;
vector<int> candy;
vector<int> visited;
vector<int> componentSize;
vector<int> componentCandy;
vector<bool> isComponentCalculated;
int totalCandy = 0;

void dfs(int node, int& size, int& totalCandy) {
    visited[node] = 1;
    size++;
    totalCandy += candy[node];
    
    for (int nextNode : adjList[node]) {
        if (!visited[nextNode]) {
            dfs(nextNode, size, totalCandy);
        }
    }
}

int main() {
    cin >> child >> rel >> minCry;

    candy.resize(child + 1);
    adjList.resize(child + 1);
    visited.assign(child + 1, 0);
    isComponentCalculated.assign(child + 1, false);
    
    for (int i = 1; i <= child; i++) {
        cin >> candy[i];
    }

    for (int i = 0; i < rel; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    for (int i = 1; i <= child; i++) {
        if (!visited[i]) {
            int size = 0;
            int totalComponentCandy = 0;
            dfs(i, size, totalComponentCandy);
            componentSize.push_back(size);
            componentCandy.push_back(totalComponentCandy);
        }
    }

    vector<int> dp(minCry, 0);

    for (int i = 0; i < componentSize.size(); i++) {
        for (int j = minCry - 1; j >= componentSize[i]; j--) {
            dp[j] = max(dp[j], dp[j - componentSize[i]] + componentCandy[i]);
        }
    }

    cout << dp[minCry - 1] << endl;

    return 0;
}
