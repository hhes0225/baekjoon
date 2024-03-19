#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int tCase;

    cin>>tCase;

    for(int i=0;i<tCase;i++){
        int input;
        cin>>input;

        vector<bool> nums;
        nums=vector<bool>(10, false);

        int beauty=0;
        
        string inputStr = to_string(input);
        for(int j=0;j<inputStr.size();j++){
            if(nums[inputStr[j]-'0']==true){
                continue;
            }
            else{
                nums[inputStr[j]-'0']=true;
            }
        }

        for(int j=0;j<nums.size();j++){
            if(nums[j]==true)
                beauty++;
        }
            
        cout<<beauty<<"\n";
    }

    return 0;
}