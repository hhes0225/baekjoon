#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    while(1){
        int length;
        int input;
        vector<int> nums;
        vector<int> rmvDupNums;
        cin>>length;

        if(length==0){
            break;
        }

        for(int i=0;i<length;i++){
            cin>>input;
            
            nums.push_back(input);
        }

        rmvDupNums.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                rmvDupNums.push_back(nums[i]);
            }
        }

        for(int i=0;i<rmvDupNums.size();i++){
            cout<<rmvDupNums[i]<<" ";
        }
        cout<<"$\n";
    }
    
    return 0;
}