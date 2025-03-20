#include <bits/stdc++.h>
using namespace std;

vector<int> signalReach;
vector<int> towers;
stack<pair<int, int>> reached;


int main() {
    int n;
    cin>>n;
    towers.resize(n);
    signalReach.assign(n, 0);

    for(auto&t:towers){
        cin>>t;
    }

    for(int i=0;i<n;i++){
        int curIdx=i;
        int curHeight=towers[i];
        
        while(!reached.empty()){
            auto [rIdx, rHeight]=reached.top();

            //보내는 타워의 높이가 더 높으면 
            if(curHeight>rHeight){
                reached.pop();
            }
            else{
                //cout<<curHeight<<"에서 보내는 요청: "<<rHeight<<"에서 받음\n";
                signalReach[curIdx]=rIdx+1;//값은 1부터 시작
                break;
            }
        }    
        reached.push({curIdx, curHeight});
    }

    for(auto s:signalReach){
        cout<<s<<" ";
    }
    cout<<"\n";

    
    return 0;
}