#include <bits/stdc++.h>
using namespace std;

set<int> places;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin>>n>>q;

    //1일 경우에만 set에 저장
    for(int i=0;i<n;i++){
        int type; cin>>type;
        if(type==1) places.insert(i+1);//1-base
    }

    int pos=1;//1-base
    
    for(int i=0;i<q;i++){
        int command;
        cin>>command;

        if(command==1){
            int idx; cin>>idx;

            //없으면 명소 등록
            if(places.find(idx)==places.end()) places.insert(idx);
            //있으면 명소 제거
            else places.erase(idx);
        }
        else if(command==2){
            int d; cin>>d;
            pos=(pos+d-1)%n+1;//1-base
        }
        else{
            //만약 명소 존재하지 않는 경우
            if(places.empty()){ cout<<-1<<"\n"; continue;}
            
            //lower_bound로 현재 위치보다 큰 값 있는지 확인
            auto it = places.lower_bound(pos);

            //존재하면->그냥 그만큼 가
            if(it!=places.end()) cout<<*it-pos<<"\n";
            
            //존재하지 않으면->한바퀴 돌아서 가장 첫번째 요소
            //무조건 첫번째 요소로 가는게 가장 빠른 길임!(시계방향만 가능하므로)
            else cout<<n-pos+*places.begin()<<"\n";
        }
    }
    return 0;
}