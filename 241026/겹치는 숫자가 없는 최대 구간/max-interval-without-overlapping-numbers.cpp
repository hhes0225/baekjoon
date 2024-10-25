#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
vector<int> dp;
unordered_map<int, int> numMap;
vector<int> nums;

void dpFunc(){
    int left=0, maxLen=0;

    for(int right=0;right<n;right++){
        numMap[nums[right]]++;

        while(numMap[nums[right]]>1){
            numMap[nums[left]]--;
            if(numMap[nums[left]]==0){
                numMap.erase(nums[left]);
            }
            left++;
        }

        dp[right]=right-left+1;
    }
}

/*
void dpFunc(){
    dp[0]=1;
    numMap[nums[0]]=1;

    for(int i=1;i<nums.size();i++){
        if(numMap.find(nums[i])!=numMap.end()){
            dp[i]=dp[i-1];
        }
        else{
            dp[i]=dp[i-1]+1;
            numMap[nums[i]]=1;
        }
    }

}
*/

int main() {
    cin>>n;

    dp.assign(n, 0);
    nums.resize(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    dpFunc();

    cout<<*max_element(dp.begin(), dp.end())<<"\n";

    return 0;
}