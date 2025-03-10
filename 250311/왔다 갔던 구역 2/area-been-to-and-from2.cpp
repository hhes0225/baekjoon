#include <bits/stdc++.h>
const int MAX=2000;
const int offset=1000;
using namespace std;

int n;
vector<pair<int, char>> command;
vector<int> simul;

int main() {
    cin >> n;
    command.resize(n);
    simul.assign(MAX, 0);

    for (auto& c:command) {
        cin >> c.first>>c.second;
    }

    int cur=offset;

    for(auto c:command){
        auto [x, dir]=c;

        if(dir=='L'){
            for(int i=0;i<=x;i++){
                simul[cur-i]++;
            }
            cur-=x;
        }
        if(dir=='R'){
            for(int i=0;i<=x;i++){
                simul[cur+i]++;
            }
            cur+=x;
        }
    }

    int ans=0;
    for(auto s:simul){
        if(s>=2) ans++;
    }

    int group=0;
    for(int i=1;i<MAX;i++){
        if(simul[i-1]<2&&simul[i]>=2) group++;
    }
    
    /*
    for(int i=985;i<1010;i++){
        cout<<i-offset<<": "<<simul[i]<<"\n";
    }
    cout<<"\n";*/
    

    cout<<ans-group<<"\n";

    return 0;
}