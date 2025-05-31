#include <bits/stdc++.h>
using namespace std;

const int MAX=100;
const int LEN=10;

int main() {
    vector<vector<int>> axis (MAX+1, vector<int>(MAX+1, 0));

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;

        for(int i=y;i<y+LEN;i++){
            for(int j=x;j<x+LEN;j++){
                axis[i][j]++;
            }
        }
    }

    int ans=0;

    for(int i=0;i<MAX+1;i++){
        for(int j=0;j<MAX+1;j++){
            if(axis[i][j]!=0){
                ans++;
            }
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}