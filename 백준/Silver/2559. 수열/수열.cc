#include <bits/stdc++.h>
using namespace std;

vector<int> temperatures;

int main() {
    int n, k;
    cin>>n>>k;

    temperatures.resize(n);

    for(auto &t:temperatures){
        cin>>t;
    }


    int tmp=0;
    for(int i=0;i<k;i++){
        tmp+=temperatures[i];
    }
    int left=0, right=k-1;

    int maxSum=tmp;

    while(right<n-1){
        tmp-=temperatures[left++];
        tmp+=temperatures[++right];
        // cout<<tmp<<"\n";

        maxSum=max(maxSum, tmp);
    }

    cout<<maxSum<<"\n";
    
    return 0;
}