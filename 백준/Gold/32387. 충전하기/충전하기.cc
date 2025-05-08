#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;

    cin>>n>>q;

    vector<int> ports(n+1, -1);
    set<int> unused;

    for(int i=0;i<=n;i++){
        unused.insert(i);
    }

    for(int i=0;i<q;i++){
        int type, input;
        cin>>type>>input;

        if(type==1){
            auto it=unused.lower_bound(input);
            if(it ==unused.end()){
                cout<<-1<<"\n";
            }
            else{
                ports[*it]=i+1;
                cout<<*it<<"\n";
                unused.erase(it);
            }
        }
        else{
            cout<<ports[input]<<"\n";
            ports[input]=-1;
            unused.insert(input);
        }
    }
    
    return 0;
}