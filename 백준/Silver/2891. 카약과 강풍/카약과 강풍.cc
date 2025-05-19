#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s,r;
    cin>>n>>s>>r;
    
    vector<int> dp(n);
    //1base
    vector<bool> damaged(n+2, false);
    vector<bool> prepared(n+2, false);

    for(int i=0;i<s;i++){
        int tmp;
        cin>>tmp;
        damaged[tmp]=true;
    }

    for(int i=0;i<r;i++){
        int tmp;
        cin>>tmp;

        //손상된 팀 자기 자신이 여분이 있으면 그걸로 커버
        if(damaged[tmp]) damaged[tmp]=false;
        else prepared[tmp]=true;
    }

    int cantStart=0;
    for(int i=1;i<=n;i++){
        if(damaged[i]){
            if(prepared[i-1]){
                damaged[i]=false;
                prepared[i-1]=false;
                continue;
            }
            else if(prepared[i+1]){
                damaged[i]=false;
                prepared[i+1]=false;
                continue;
            }
        }
    }

    for(auto d:damaged){
        // cout<<d<<" ";
        if(d) cantStart++;
    }

    cout<<cantStart<<"\n";
    
    
    
    return 0;
}