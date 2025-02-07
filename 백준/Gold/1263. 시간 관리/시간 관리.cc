#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

vector<PII> works;

int main() {
    int n;
    cin>>n;

    works.resize(n);

    for(auto& w:works){
        cin>>w.first>>w.second;
    }


    //정렬

    sort(works.begin(), works.end(), [](PII a, PII b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        else{
            return a.first>b.first;
        }
    });

    /*
    for(auto w:works){
        cout<<w.first<<" "<<w.second<<"\n";
    }
    */

    //일 마칠 수 있는 가장 늦은 시간

    int latestStart=works[0].second-works[0].first;

    for(int i=1;i<n;i++){
        auto [duration, deadline]=works[i];
        if(latestStart==deadline){
            latestStart-=duration;
        }
        else if(latestStart>deadline){
            latestStart=deadline-duration;
        }
        else{//latestStart<deadline;
            latestStart-=duration;
        }
    }

    
    
    if(latestStart>=0){
        cout<<latestStart<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
    
    
    return 0;
}