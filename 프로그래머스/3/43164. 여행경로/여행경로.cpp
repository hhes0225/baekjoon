#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 유방향 그래프
// DFS
unordered_map<string, vector<string>> graph;
unordered_map<string, vector<bool>> visited;
vector<string> route;
vector<string> answer;
bool found = false;

void makeGraph(vector<vector<string>> tickets){
    for(int i = 0; i < tickets.size(); i++){
        string from = tickets[i][0];
        string to = tickets[i][1];

        if(graph.find(from) == graph.end()) { // map에 존재하지 않으면
            graph[from] = vector<string>();
            visited[from] = vector<bool>();
        }

        graph[from].push_back(to);
        visited[from].push_back(false);
    }

    for(auto &it : graph){
        sort(it.second.begin(), it.second.end()); // 알파벳 순으로 정렬
    }
}

void dfs(string location, int remainTickets){
    route.push_back(location);
    
    if(remainTickets <= 0){
        if(!found) { // 처음으로 모든 티켓을 사용한 경로를 찾았을 때
            answer = route;
            found = true;
        }
        route.pop_back();
        return;
    }
    
    for(int i = 0; i < graph[location].size(); i++){
        if(!visited[location][i]){ // 방문하지 않은 경우
            visited[location][i] = true;
            dfs(graph[location][i], remainTickets - 1);
            visited[location][i] = false;
        }
    }
    
    route.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    makeGraph(tickets);
    dfs("ICN", tickets.size());
    return answer;
}
