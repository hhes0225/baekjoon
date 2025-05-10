#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> contestants;
    vector<int> finishTime;
    
    contestants.resize(n);
    finishTime.resize(n);

    for(auto &c: contestants){
        cin>>c;
    }

    queue<pair<int, int>> pizzaQ;

    for(int i=0;i<n;i++){
        pizzaQ.push({i, contestants[i]});
    }

    int time=1;
    while(!pizzaQ.empty()){
        auto [idx, needPizza]=pizzaQ.front();
        pizzaQ.pop();

        if(needPizza-1==0){
            finishTime[idx]=time;
        }
        else{
            pizzaQ.push({idx, needPizza-1});
        }
        
        time++;
    }

    for(auto t:finishTime){
        cout<<t<<" ";
    }
    cout<<"\n";

    
    return 0;
}