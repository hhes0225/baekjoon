#include <bits/stdc++.h>
using namespace std;

struct Lecture{
    int id=0;
    int from=0;
    int to=0;
    int assigned=0;
};

struct compare{
    bool operator()(Lecture&a, Lecture&b){
        return a.to>b.to;//pq에서는 오름차순으로 동작 
    }
};

vector<Lecture> lecs;

int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int d,f,t;
        cin>>d>>f>>t;

        lecs.push_back({d,f,t,0});
    }

    //시작 순서 기준으로 오름차순 정렬
    sort(lecs.begin(), lecs.end(), [](Lecture a, Lecture b){
       if(a.from!=b.from){
           return a.from<b.from;
       } 
       else return a.to<b.to; 
    });

    //pq는 끝나는 시간 기준으로 오름차순 정렬
    priority_queue<Lecture, vector<Lecture>, compare> pq;
    int idx=1;
    for(auto& l: lecs){
        if(pq.empty()){
            l.assigned=pq.size()+1;
            pq.push(l);
        }
        else{
            auto earliestEnd=pq.top();
            // cout<<earliestEnd.from<<" "<<earliestEnd.to<<" "<<earliestEnd.assigned<<"\n";

            
            //한 강의 종료시간과 다른 강의 시작시간 겹치는 것은 상관없음
            if(earliestEnd.to<=l.from){
                l.assigned=earliestEnd.assigned;//강의에 교실 배정
                earliestEnd.to=l.to;//종료시간 갱신

                //바뀐 종료시간 기준으로 갱신
                pq.push(earliestEnd);
                pq.pop();
            }
            else{//겹치는 경우
                l.assigned=pq.size()+1;
                pq.push(l);
            }
        }
    }

    // for(auto [i,f,t,a]:lecs){
    //     cout<<i<<" "<<f<<" "<<t<<" "<<a<<"\n";
    // }

    
    cout<<pq.size()<<"\n";

    //강의 번호 1~n 순서로 출력하기 위해 재정렬
    //처음에 입력순인줄 알고 unordered_map 사용했더니 73%에서 틀렸습니다 뜸
    //(강의 번호 기준 오름차순)
    sort(lecs.begin(), lecs.end(), [](Lecture a, Lecture b){
       return a.id<b.id; 
    });

    for(auto l:lecs){
        cout<<l.assigned<<"\n";
    }
    
    return 0;
}