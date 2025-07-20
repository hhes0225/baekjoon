#include <bits/stdc++.h>
using namespace std;

bool result=false;

void dfs(const string& src, string dst){
    if(result) return;
    if(src.size()==dst.size()){
        if(src==dst) {
            result=true;
            return;
       }
    }
    
    // cout<<"front: "<< dst.front()<<"\n";

    if(dst.front()=='B'){
        //case 1, 2 둘 다 가능
        string tmp=dst;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();

        // cout<<"2: "<<tmp<<"\n";
        dfs(src, tmp);
    }
    
    if(dst.back()=='A'){
        //case 1만 가능
        string tmp=dst;
        tmp.pop_back();

        // cout<<"1: "<<tmp<<"\n";
        dfs(src, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string src, dst;
    cin>>src>>dst;


    dfs(src, dst);

    if(result) cout<<"1\n";
    else cout<<"0\n";
    
    return 0;
}