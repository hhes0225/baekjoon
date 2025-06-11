#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m));

        bool isArranged=true;

        for(auto &j:arr){
            for(auto& k:j) cin>>k;
        }

        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                int k=a+1, l=b+1;

                if(k<0||k>=n||l<0||l>=m) continue;

                if(arr[a][b]+arr[k][l]>arr[a][l]+arr[k][b]){
                    isArranged=false;
                    break;
                }
            }
        }

        if(isArranged) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}