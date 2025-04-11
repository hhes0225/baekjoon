#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main() {
    int n;
    cin>>n;

    priority_queue<PII, vector<PII>, greater<PII>> pq;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;

        if(tmp!=0)
            pq.push({abs(tmp), tmp});
        else{
             if(pq.size()==0) cout<<"0\n";
            else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
    }

    
    
    return 0;
}