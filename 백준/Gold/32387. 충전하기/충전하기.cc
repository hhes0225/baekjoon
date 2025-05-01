#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> portStatus;
    set<int> freePorts;

    portStatus.assign(n+1, -1);

    for(int i=0;i<n;i++){
        freePorts.insert(i+1);
    }

    // for(auto p:portStatus){
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }

    for(int i=0;i<q;i++){
        int type, input;
        cin>>type>>input;

        if(type==1){
            //set에 lower_bound 내장함수 있음!!!
            auto it=freePorts.lower_bound(input);
            if(it!=freePorts.end()){
                portStatus[*it]=i+1;//몇 번째 쿼리에 처리됐는지 저장
                cout<<*it<<"\n";//몇 번째 쿼리?
                freePorts.erase(it);//미사용 포트 set에서 제거
            }
            else{
                cout<<-1<<"\n";
            }
        }
        else{
            cout<<portStatus[input]<<"\n";//사용중 포트에서 어디 사용중이었는지 출력
            freePorts.insert(input);//사용중 포트->미사용 포트 set으로
            portStatus[input]=-1;//미사용 처리
        }
    }
    
    return 0;
}