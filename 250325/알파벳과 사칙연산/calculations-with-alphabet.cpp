#include <bits/stdc++.h>

using namespace std;

string expression;
int maxResult=0;
vector<int> nums;

bool isAlpha(char c){
    return (c>='a'&&c<='f');
}

int calculate(vector<int>&nums, string expression){
    int nIdx=1;
    int result=nums[0];
    char op;

    for(int i=1;i<expression.size();i++){
        if(!isAlpha(expression[i])){
            op=expression[i];
        }
        else{
            switch(op){
                case'+' : result+=nums[nIdx]; break;
                case'-' : result-=nums[nIdx]; break;
                case '*': result*=nums[nIdx]; break;
            }
            nIdx++;
        }
    }

    return result;
}


void backtracking(int leftCnt){
    if(leftCnt==0){
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        
        int result = calculate(nums, expression);
        //cout<<calculate(nums, expression)<<"\n";

        //계산
        maxResult=max(maxResult, result);

        return;
    }

    //해당 자리에 1~4 다 넣어보기
    for(int i=1;i<=4;i++){
        nums.push_back(i);
        backtracking(leftCnt-1);
        nums.pop_back();
    }


}

int main() {
    int alphaCnt=0;
    cin >> expression;

    for(auto e:expression){
        if(e>='a'&&e<='f') alphaCnt++;
    }

    backtracking(alphaCnt);

    cout<<maxResult<<"\n";

    return 0;
}
