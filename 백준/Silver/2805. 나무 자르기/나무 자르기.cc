#include <bits/stdc++.h>
using namespace std;

vector<int> trees;

bool canBringM(int limit, int m){
    long long bring=0;

    for(auto t:trees){
        if(t-limit>=0)
            bring +=(t-limit);
    }

    // cout<<bring<<" ";

    return (bring>=m);
}

int main() {
    int n, m;
    cin>>n>>m;

    trees.resize(n);

    for(int& t:trees) cin>>t;

    sort(trees.begin(), trees.end());

    //자르는 높이, mid로 나무 잘랐을 때 잘린 부분이 m이상이 되게 하겠다.
    int left=0, right=trees.back();

    while(left<=right){
        int mid=(left+right)/2;
        // cout<<left<<" "<<right<<" "<<mid<<" :";

        //최댓값의 최소화
        if(canBringM(mid, m)){
            // cout<<"true\n";
            left=mid+1;
            
        }
        else{
            // cout<<"false\n";
            right=mid-1;
        }
    }

    cout<<right;
    
    return 0;
}