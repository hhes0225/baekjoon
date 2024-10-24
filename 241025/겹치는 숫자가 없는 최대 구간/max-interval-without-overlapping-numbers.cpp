#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
vector<int> num;
vector<int> dp;

int dpFunc(){
    dp[0]=1;

    for(int i=1;i<len;i++){
        int left=0;
        int dup=-1;
        int right=i-1;

        while(left<right){
            //cout<<i<<": "<<num[i]<<", "<<num[left]<<"\n";
            if(num[i]==num[left]){
                dup=left;
            }
            left++;
        }

        if(dup==-1){
                dp[i]=dp[i-1]+1;
        }
        else{
            dp[i]=i-dup;
        }
    }

    /*
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }
    */

    return *max_element(dp.begin(), dp.end());
}

int main() {
    cin>>len;

    num.resize(len);
    dp.resize(len);

    for(int i=0;i<len;i++){
        cin>>num[i];
    }

    cout<<dpFunc()<<"\n";

    return 0;
}