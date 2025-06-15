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
        return a.to>b.to;//pq에서는 오름차순으로 동
    }
};

vector<Lecture> lecs_unsorted;
vector<Lecture> lecs;
unordered_map<int, Lecture> lecInfo;

int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int d,f,t;
        cin>>d>>f>>t;

        lecs_unsorted.push_back({d,f,t,0});
    }

    lecs=lecs_unsorted;

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
                l.assigned=earliestEnd.assigned;
                earliestEnd.to=l.to;
                pq.push(earliestEnd);
                pq.pop();
                
            }
            else{//겹치는 경우
                l.assigned=pq.size()+1;
                pq.push(l);
            }
        }
    }

    cout<<pq.size()<<"\n";

    // for(auto [i,f,t,a]:lecs){
    //     cout<<i<<" "<<f<<" "<<t<<" "<<a<<"\n";
    // }

    //  for(auto l:lecs){
    //      lecInfo[l.id]=l;
    //  }

    // for(auto &l:lecs_unsorted){
    //     l.assigned=lecInfo[l.id].assigned;
    // }

    // for(auto l:lecs_unsorted){
    //     cout<<l.assigned<<"\n";
    // }

    sort(lecs.begin(), lecs.end(), [](Lecture a, Lecture b){
       return a.id<b.id; 
    });

    for(auto l:lecs){
        cout<<l.assigned<<"\n";
    }
    
    return 0;
}