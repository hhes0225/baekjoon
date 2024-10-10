#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define endl "\n"
#define MAX 50
#define KEY_MAX 255

using namespace std;

/*
    https://yabmoons.tistory.com/407
    
    1. bfs를 사용하여 로봇부터 열쇠까지 최소 거리를 구한다
    2. 크루스칼 알고리즘 사용하여 최소 신장 트리로 
*/

int N, M, Key_Num, Answer;
int Key_Number[MAX][MAX];
int Parent[KEY_MAX];
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
bool Flag = true; // 원하는 경로 찾지 못하면 false
pair<int, int> Start;
vector<pair<int, int>> Key;
vector<pair<int, pair<int, int>>> Edge;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input() {
    Key_Num = 1;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'S') {
                Start.first = i;
                Start.second = j;
            }
            else if (MAP[i][j] == 'K') {
                Key.push_back(make_pair(i, j));
                Key_Number[i][j] = Key_Num++;
            }
        }
    }
}

void BFS(int Sx, int Sy, int Ex, int Ey, int Node1, int Node2) {
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(Sx, Sy), 0));
    Visit[Sx][Sy] = true;

    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();

        if (x == Ex && y == Ey) {
            Edge.push_back(make_pair(Cnt, make_pair(Node1, Node2)));
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == '1') continue;
                if (Visit[nx][ny] == true) continue;

                Visit[nx][ny] = true;
                Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
            }
        }
    }
    Flag = false;
}

void Calculate_Distance() {
    for (int i = 0; i < Key.size(); i++) {
        int x = Key[i].first;
        int y = Key[i].second;
        BFS(Start.first, Start.second, Key[i].first, Key[i].second, 0, Key_Number[x][y]);

        if (Flag == false) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < Key.size(); i++) {
        int x = Key[i].first;
        int y = Key[i].second;

        for (int j = i + 1; j < Key.size(); j++) {
            int xx = Key[j].first;
            int yy = Key[j].second;

            BFS(x, y, xx, yy, Key_Number[x][y], Key_Number[xx][yy]);
            if (Flag == false) {
                cout << -1 << endl;
                return;
            }
        }
    }
}

int Find_Parent(int A) {
    if (A == Parent[A]) return A;
    else return Parent[A] = Find_Parent(Parent[A]);
}

bool Same_Parent(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);

    if (A == B) return true;
    return false;
}

void Union(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);

    Parent[B] = A;
}

void Kruskal() {
    for (int i = 0; i < Key_Num; i++) Parent[i] = i;
    sort(Edge.begin(), Edge.end());

    for (int i = 0; i < Edge.size(); i++) {
        int Cost = Edge[i].first;
        int Node1 = Edge[i].second.first;
        int Node2 = Edge[i].second.second;

        if (Same_Parent(Node1, Node2) == false) {
            Union(Node1, Node2);
            Answer = Answer + Cost;
        }
    }
}

void Solution() {
    Calculate_Distance();
    if (Flag == false) return;

    Kruskal();
    cout << Answer << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}
