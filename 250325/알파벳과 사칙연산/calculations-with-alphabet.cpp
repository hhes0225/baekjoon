#include <bits/stdc++.h>

using namespace std;

string expression;
int maxResult=INT_MIN;
vector<int> nums;
unordered_set<char> alpha;
unordered_map<char, int> dict;


bool isAlpha(char c){
    return (c>='a'&&c<='f');
}

int calculate(vector<int>&nums, string expression){
    int result=dict[expression[0]];
    char op;

    for(int i=1;i<expression.size();i++){
        if(!isAlpha(expression[i])){
            op=expression[i];
        }
        else{
            switch(op){
                case'+' : result+=dict[expression[i]]; break;
                case'-' : result-=dict[expression[i]]; break;
                case '*': result*=dict[expression[i]]; break;
            }
        }
    }

    return result;
}


void backtracking(int leftCnt){
    if(leftCnt==0){
        int nIdx=0;

        for(auto a:alpha){
            dict[a]=nums[nIdx++];
        }
        
        int result = calculate(nums, expression);
        //cout<<result<<"\n";

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
    cin >> expression;

    for(auto e:expression){
        if(e>='a'&&e<='f') alpha.insert(e);
    }

    backtracking(alpha.size());

    cout<<maxResult<<"\n";

    return 0;
}
