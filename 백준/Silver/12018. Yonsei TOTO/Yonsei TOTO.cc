#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> minCredit;

    for(int i=0;i<n;i++){
        int apply, available;
        cin>>apply>>available;

        vector<int> credits;
        credits.resize(apply);

        for(auto &c:credits) cin>>c;

        sort(credits.begin(), credits.end(), [](int a, int b){
            return a>b;
        });

        if(apply>=available){
            minCredit.push_back(credits[available-1]);
        }
        else{
            minCredit.push_back(1);
        }
        
    }

    sort(minCredit.begin(), minCredit.end());

    vector<int> minCreditSum;
    minCreditSum.resize(minCredit.size());
    minCreditSum[0]=minCredit[0];
    
    for(int i=1;i<minCredit.size();i++){
        minCreditSum[i]=minCreditSum[i-1]+minCredit[i];
    }

    // for(auto mi:minCreditSum) cout<<mi<<" ";
    // cout<<"\n";

    int idx=upper_bound(minCreditSum.begin(), minCreditSum.end(), m)-minCreditSum.begin();

    cout<<idx<<"\n";
    
    return 0;
}