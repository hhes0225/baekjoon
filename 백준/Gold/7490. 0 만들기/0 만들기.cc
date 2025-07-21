#include <bits/stdc++.h>
using namespace std;

vector<char>nums;
vector<string> op;
//+, -, 공백 

string makeString(int n){
    string result="";

    for(int i=0;i<n-1;i++){
        result+=nums[i];
        result+=op[i];
    }

    result+=nums[n-1];

    return result;
}

void printString(string str){
    cout<<str[0];
    for(int i=1;i<str.size();i++){
        if((str[i-1]!='+'&&str[i-1]!='-')&&
            (str[i]!='+'&&str[i]!='-')) cout<<" ";
        cout<<str[i];
    }

    cout<<"\n";
}

void setNumbers(int n){
    nums.resize(n);
    for(int i=0;i<n;i++){
        nums[i]=(i+1)+'0';
    }
}

int calculateResult(int n){
    string str=makeString(n);
    int result=0;
    int sign=1;

    string tmp="";

    for(int i=0;i<str.size();i++){
        if(str[i]=='+'){
            // cout<<tmp<<" gonna be plus\n";
            result+=(stoi(tmp)*sign);
            tmp="";
            sign=1;
            continue;
        }
        if(str[i]=='-'){
            // cout<<tmp<<" gonna be minus\n";
            result+=(stoi(tmp)*sign);
            tmp="";
            sign=-1;
            continue;
        }

        tmp+=str[i];
        // cout<<t
    }
    result+=(stoi(tmp)*sign);

    // cout<<result<<"\n";
    
    return result;
}




void backtracking(int lim, int n){
    if(lim==0){
        //nums와 op 조합으로 실제 계산하는 함수
        //만약 0이면 해당 nums와 op조합 출력

        if(calculateResult(n)==0){
            printString(makeString(n));
        }

        return;
    }

    op.push_back("");
    backtracking(lim-1, n);
    op.pop_back();

    op.push_back("+");
    backtracking(lim-1, n);
    op.pop_back();

    op.push_back("-");
    backtracking(lim-1, n);
    op.pop_back();

    
}

int main() {
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        // cout<<"case: "<<n<<"\n";

        setNumbers(n);

        //연산자는 n-1개 뽑아야 함
        backtracking(n-1, n);
        
        cout<<"\n";
        nums.clear();
        op.clear();
    }
    return 0;
}