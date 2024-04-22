#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int tCase;
    cin>>tCase;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0;i<tCase;i++){
        int howMany;
        cin>>howMany;
        
        vector<int> nums;
        nums.resize(howMany);

        for(int j=0;j<nums.size();j++){
            cin>>nums[j];
        }

        sort(nums.begin(), nums.end());
        cout<<nums[0]<<" "<<nums[nums.size()-1]<<"\n";
    }

    return 0;
}