#include <bits/stdc++.h>
const int MAX=10000;
const int offset=5000;
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
                simul[cur-1]++;
                
                cur--;
            }
        }
        if(dir=='R'){
            for(int i=1;i<=x;i++){
                simul[cur]++;

                cur++;
            }   
        }

        //cout<<"cur: "<<cur-offset<<"\n";
    }

    int ans=0;
    for(auto s:simul){
        if(s>=2) ans++;
    }

    int group=0;
    // bool inGroup = false;
    // for (int i = 0; i < MAX; i++) {
    //     if (simul[i] >= 2) {
    //         if (!inGroup) {
    //             group++;
    //             inGroup = true;
    //         }
    //     } else {
    //         inGroup = false;
    //     }
    // }
    
    // for(int i=0;i<MAX;i++){
    //     if(simul[i]>0)
    //         cout<<i-offset<<": "<<simul[i]<<"\n";
    // }
    //cout<<"\n";
    

    cout<<ans<<"\n";

    return 0;
}