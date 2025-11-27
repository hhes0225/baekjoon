#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int n,k,s;
    cin>>n>>k>>s;
    
    int totalDistance=0;
    
    
    vector<PII> apt;
    priority_queue<PII> leftApt;
    priority_queue<PII> rightApt;
    
    apt.resize(n);
    
    for(auto&a:apt){
        cin>>a.first>>a.second;
    }
    
    for(auto a:apt){
        auto [pos, stu]=a;
        
        if(pos<s){//left
            leftApt.push({abs(pos-s), stu});    
        }
        else{//right
            rightApt.push({abs(pos-s), stu});
        }
    }
    
    //한번에 멀리 갔다가 돌아오는길에 가까운애들 픽업
    while(!leftApt.empty()){//학교 왼쪽 아파트 순회
        int curStudent=0;
        
        auto[d, s]=leftApt.top();
        leftApt.pop();
        
        totalDistance+=(d*2);
        
        if(k>=s){
            curStudent+=s;
        }
        else{
            leftApt.push({d, s-k});
            continue;
        }
        
        while(curStudent<k&& !leftApt.empty()){//스쿨버스 정원 찰 때까지 태우기
            auto[nd, ns]=leftApt.top();
            leftApt.pop();

            //빈자리에 다 태울 수 있으면 다 태우고 아파트 큐에서 뺌
            if(k-curStudent>=ns){
                curStudent+=ns;
            }
            else{//빈자리에 다 못태우면 아파트 큐에 그대로 둠
                int rest=abs(ns-(k-curStudent));
                leftApt.push({nd, rest});
                break;
            }
        }
    }

    
    
    while(!rightApt.empty()){//학교 오른쪽 아파트 순회
        //출발지(원래 사람 태우고 있더라도 내리고 다시 출발발)
        int curStudent=0;
        
        auto[d, s]=rightApt.top();
        rightApt.pop();
        
        totalDistance+=(d*2);
        
        if(k>=s){
            curStudent+=s;
        }
        else{
            rightApt.push({d, s-k});
            continue;
        }
        
        
        while(curStudent<k && !rightApt.empty()){//스쿨버스 정원 찰 때까지 태우기
            auto[nd, ns]=rightApt.top();
            rightApt.pop();

            
            //빈자리에 다 태울 수 있으면 다 태우고 아파트 큐에서 뺌
            if(k-curStudent>=ns){
                curStudent+=ns;
            }
            else{//빈자리에 다 못태우면 아파트 큐에 다시 푸시
                int rest=abs(ns-(k-curStudent));
                rightApt.push({nd, rest});
                break;
            }

        }
    }

    cout<<totalDistance<<"\n";
    
    
    
    return 0;
}