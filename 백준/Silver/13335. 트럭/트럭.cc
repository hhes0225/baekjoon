#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, l;
    cin>>n>>w>>l;

    queue<int> truck;
    deque<pair<int, int>> bridge;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        truck.push(a);
    }

    int cnt=0, total=0;

    while(1){
        if(truck.empty() && bridge.empty()){
            cout<<cnt+1;
            break;
        } else cnt++;

        //대기중인 트럭이 있고,
        //무게 하중이 버틸 수 있는 경우 다리에 올리기
        if(!truck.empty() && total+truck.front()<=l){
            bridge.push_back({truck.front(), 0});
            total+=truck.front();
            truck.pop();
        }

        //앞으로 한칸씩 전진
        for(int i=0;i<bridge.size();i++){
            bridge[i].second++;
        }

        //다리 빠져나왔을 경우
        //총 다리에 올라와있는 차 무게에서 빠져나온 트럭 무게 제거
        //브리지에서 빼기
        if(bridge.front().second==w){
            total-=bridge.front().first;
            bridge.pop_front();
        }
    }
    
    return 0;
}