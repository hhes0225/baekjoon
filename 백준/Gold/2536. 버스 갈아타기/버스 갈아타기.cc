#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

struct Bus{
    int num;
    bool isHorizontal;
    pair<int, int> startPos, endPos;
};

int m, n;
int k;

vector<Bus> buses;
vector<vector<int>> adjList;
/*
    수평-수평 교차
    : 두 버스가 같은 x좌표, 두 버스의 y구간이 겹치면 교차

    수직-수직 교차
    : 두 버스가 같은 y좌표, 두 버스의 x구간이 겹치면 교차

    수평-수직 교차
    : 수평 버스의 x좌표가 수직 버스의 x구간 내에 있고,
    수직 버스의 y좌표가 수평 버스의 y구간 내에 있으면 교차
*/

int BFS(int srcX, int srcY, int dstX, int dstY){
    vector<int> visited(k+1, -1);
    vector<bool> isDst(k+1, false);
    queue<int> q;

    //시작점 지나는 노선 큐에 넣기
    for(int i=1;i<=k; i++){
        if(buses[i].isHorizontal){
            if(buses[i].startPos.first != srcX||
                buses[i].startPos.second>srcY||buses[i].endPos.second<srcY){
                continue;
                }
        }
        else{
            if(buses[i].startPos.second!=srcY||
                buses[i].startPos.first>srcX||buses[i].endPos.first<srcX){
                continue;
                }
        }

        q.push(buses[i].num);
        visited[buses[i].num]=1;
    }

    //도착점 지나는 버스노선 표시
    for(int i=1;i<=k;i++){
        if(buses[i].isHorizontal){
            if(buses[i].startPos.first==dstX&&
                buses[i].startPos.second<=dstY&&buses[i].endPos.second>=dstY){
                isDst[buses[i].num]=true;
                }
        }
        else{
            if(buses[i].startPos.second==dstY&&
                buses[i].startPos.first<=dstX && buses[i].endPos.first>=dstX){
                isDst[buses[i].num]=true;
                }
        }
    }

    int busIdx, transferCnt, minTransfer;

    while(!q.empty()){
        busIdx=q.front();
        q.pop();

        transferCnt=visited[busIdx];

        if(isDst[busIdx]){
            minTransfer=transferCnt;
            break;
        }

        int nextBus;
        for(int i=0;i<adjList[busIdx].size();i++){
            nextBus=adjList[busIdx][i];
            if(visited[nextBus]==-1){
                q.push(nextBus);
                visited[nextBus]=transferCnt+1;
            }
        }
    }

    return minTransfer;
}

bool isSameHorizontalLine(Bus a, Bus b, bool isSameDirection){
    bool result;
    auto [aStartX, aStartY]=a.startPos;
    auto [aEndX, aEndY]=a.endPos;
    auto [bStartX, bStartY]=b.startPos;
    auto [bEndX, bEndY]=b.endPos;
    
    if(isSameDirection){
        result = (aStartX==bStartX)&&(bEndY>=aStartY)&&(aEndY>=bStartY);
    }
    else{
        result = ((aStartX>=bStartX)&&(bEndX>=aStartX))&&
            ((bStartY>=aStartY)&&(aEndY>=bStartY));
    }

    return result;
}
bool isSameVerticalLine(Bus a, Bus b, bool isSameDirection){
    bool result;
    auto [aStartX, aStartY]=a.startPos;
    auto [aEndX, aEndY]=a.endPos;
    auto [bStartX, bStartY]=b.startPos;
    auto [bEndX, bEndY]=b.endPos;
    
    if(isSameDirection){
        result = (aStartY==bStartY)&&(bEndX>=aStartX)&&(aEndX>=bStartX);
    }
    else{
        result = ((bStartX>=aStartX)&&(aEndX>=bStartX))&&
            ((aStartY>=bStartY)&&(bEndY>=aStartY));
    }

    return result;
}

int main() {

    int srcX, srcY, dstX, dstY;
    
    cin>>m>>n;
    cin>>k;

    adjList = vector<vector<int>> (k+1);
    buses = vector<Bus>(k+1);

    for(int i=1;i<=k;i++){
        int k, x1, y1, x2, y2;
        cin>>k>>x1>>y1>>x2>>y2;
        
        buses[i].num=k;

        //수평 노선? 수직 노선?
        if(x1==x2) buses[i].isHorizontal=true;
        else buses[i].isHorizontal=false;//vertical

        //원점(1,1)에 가까운 값을 시작점으로
        if(x1>x2||y1>y2){
            buses[i].startPos={x2,y2};
            buses[i].endPos={x1,y1};
        }
        else{
            buses[i].startPos={x1, y1};
            buses[i].endPos={x2,y2};
        }

        Bus& curBus = buses[i], compareBus;

        //교차 여부 따져서 adjList 만들기
        for(int j=1;j<i;j++){
            compareBus=buses[j];
            //노선 방향 같을 경우
            if(curBus.isHorizontal==compareBus.isHorizontal){
                if(curBus.isHorizontal){
                    if(!isSameHorizontalLine(curBus, compareBus, true)) continue;
                }
                else{
                    if(!isSameVerticalLine(curBus, compareBus, true)) continue;
                }
            }
            else{//노선 방향 다를 경우
                if(curBus.isHorizontal){
                    if(!isSameHorizontalLine(curBus, compareBus, false)) continue;
                }
                else{
                    if(!isSameVerticalLine(curBus, compareBus, false)) continue;
                }
            }

            adjList[curBus.num].push_back(compareBus.num);
            adjList[compareBus.num].push_back(curBus.num);
        }
        
    }

    cin>>srcX>>srcY>>dstX>>dstY;

    cout<<BFS(srcX, srcY, dstX, dstY)<<"\n";
    
    return 0;
}