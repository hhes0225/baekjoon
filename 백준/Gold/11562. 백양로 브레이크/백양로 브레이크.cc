#include <bits/stdc++.h>
using namespace std;
const int MAX = 987'654'321;

vector<vector<int>> graphTable;
vector<tuple<int, int, int>> edges;

/*
    뭔가 그래프 느낌이 나는 문제.
    문제만 읽었을 때는 백트래킹인가? 했는데
    
    예제까지 보니까 쿼리로 FROM src_node TO dst_node 까지의
    최소 양방향 변환 횟수를 반환해야 하므로
    
    FROM 전체 노드 TO 전체 노드를 알 수 있는
    플로이드 워셜이 적절하다고 생각했음
    (+플로이드 워셜은 DP이므로 최소 횟수 카운트에도 적합하다고 생각)
    
    대신 DP 테이블에 비용을 src부터 dst까지 가기 위해 필요한
    ""최소 일반통행->양방향 전환 횟수""로 설정
*/

int main() {
    int n, m;
    cin>>n>>m;

    graphTable.assign(n+1, vector<int>(n+1, MAX));
    edges.resize(m);

    //FROM 자기자신 TO 자기자신 경로 0
    for(int i=0;i<n+1;i++){
        graphTable[i][i]=0;
    }

    //간선 정보 입력
    for(auto& e:edges){
        auto& [from, to, bidirection]=e;
        cin>>from>>to>>bidirection;
    }

    //각 간선에 대한 정보 입력받아 0으로 초기화
    //연결되어있으므로 양방향 통행으로 바꿀 필요 X
    for(auto e:edges){
        auto [from, to, bidirection]=e;

        if(bidirection==0){//단방향
            graphTable[from][to]=0;
            graphTable[to][from]=1;//양방향으로 바꾸는 경우, count up
        }
        else{//양방향
            graphTable[from][to]=0;
            graphTable[to][from]=0;
        }
    }
    
    /*
    for(auto i:graphTable){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    */

    //플로이드-워셜
    for(int k=1;k<n+1;k++){//중간 경로 찢기(D_ak~D_kb)
        for(int a=1;a<n+1;a++){//(D_ab 의 a(from))
            for(int b=1;b<n+1;b++){//D_ab 의 b(to)
                graphTable[a][b]=min(graphTable[a][b], graphTable[a][k]+graphTable[k][b]);
            }
        }
    }

    /*
    for(auto i:graphTable){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    */

    //쿼리
    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        int from, to;
        cin>>from>>to;

        cout<<graphTable[from][to]<<"\n";
    }
    
    return 0;
}