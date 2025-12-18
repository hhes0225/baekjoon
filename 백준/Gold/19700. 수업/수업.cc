#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<vector<int>> teams;
multiset<int> teamCnt;//사람수
vector<PII> student;

int main()
{
    int n;
    cin>>n;
    
    student.resize(n);
    
    for(auto &s:student){
        cin>>s.first>>s.second;
    }
    
    sort(student.begin(), student.end(), [](PII a, PII b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        else{
            return a.second<b.second;
        }
    });
    
    
    // for(auto s:student){
    //     cout<<s.first<<" "<<s.second<<"\n";
    // }
    
    
    for(auto s: student){
        auto[height, limit]=s;
        
        if(teamCnt.empty()){//팀이 없음. 새팀 만듦
            teams.push_back({height});
            teamCnt.insert(1);
            continue;
        }
        
        if(limit==1){//내가 1등이어야 함. 새팀 만듦
            teams.push_back({height});
            teamCnt.insert(1);
            continue;
        }
        
        
        auto it=teamCnt.lower_bound(limit);
        //auto [minPpl, teamNo]=teamCnt.top();
        
        if(it==teamCnt.begin()){
            //모든 팀의 인원수가 limit 이상임->새팀 생성성
            teams.push_back({height});
            teamCnt.insert(1);
        }
        else{//it 바로 앞 원소가 limit보다 작으면서 가장 큰 값
            
            it--;
            int curSize=*it;
            
            //인원수 변경
            teamCnt.erase(it);
            teamCnt.insert(curSize+1);
        }
        
        //처음에는 적은 인원수 팀부터 채워넣는 식으로 했는데,
        //이 경우 최적의 그리디한 방법이 아님
        
    }
    
    cout<<teamCnt.size()<<"\n";
    
    // for(auto i:teams){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    

    return 0;
}