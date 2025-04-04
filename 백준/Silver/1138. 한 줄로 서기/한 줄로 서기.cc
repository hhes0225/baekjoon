#include <bits/stdc++.h>
using namespace std;

vector<int> heights;
vector<int> standing;

int main() {
    int n;
    cin>>n;

    heights.resize(n);
    standing.assign(n, -1);

    for(auto&h:heights){
        cin>>h;
    }

    for(int i=0;i<n;i++){
        int taller=heights[i];
        int pos=0;

        //cout<<"큰사람 왼쪽에 "<<taller<<"만큼 존재\n";


        //해당 키에서 큰 사람 단서를 기준으로 배치할 곳 탐색
        for(int j=0;j<n && taller>0;j++){
            if(standing[j]==-1){
                taller--;
                pos=j+1;
            }
            //cout<<"큰사람 왼쪽에 "<<taller<<"만큼 남고, 적어도 "<<pos<<"에 있어야 함\n";
        }

        for(int j=pos;j<n;j++){
            if(standing[j]==-1){
                standing[j]=i+1;
                break;
            }
        }
        
    }

    for(auto s:standing) cout<<s<<" ";
    cout<<"\n";
    
    return 0;
}